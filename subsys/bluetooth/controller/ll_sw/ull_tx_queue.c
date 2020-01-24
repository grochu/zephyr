/*
 * Copyright (c) 2020 Demant
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "ull_tx_queue.h"

void ull_tx_q_init(struct ull_tx_q *queue)
{
	queue->pause_data = 0;
	sys_slist_init(&queue->tx_list);
	sys_slist_init(&queue->data_list);
}

void ull_tx_q_pause_data(struct ull_tx_q *queue)
{
	queue->pause_data = 1U;
}

void ull_tx_q_resume_data(struct ull_tx_q *queue)
{
	queue->pause_data = 0U;

	/* move all paused data to the tail of tx list */
	sys_slist_merge_slist(&queue->tx_list, &queue->data_list);
}

void ull_tx_q_enqueue_data(struct ull_tx_q *queue, struct node_tx *tx)
{
	sys_slist_t *list;

	if (queue->pause_data) {
		/* enqueue data pdu into paused data wait list */
		list = &queue->data_list;
	} else {
		/* enqueue data pdu into tx list */
		list = &queue->tx_list;
	}

	sys_slist_append(list, (sys_snode_t *)tx);
}

void ull_tx_q_enqueue_ctrl(struct ull_tx_q *queue, struct node_tx *tx)
{
	/* enqueue ctrl pdu into tx list */
	sys_slist_append(&queue->tx_list, (sys_snode_t *)tx);
}

struct node_tx *ull_tx_q_dequeue(struct ull_tx_q *queue)
{
	struct node_tx *tx;

	tx = (struct node_tx *)sys_slist_get(&queue->tx_list);

	return tx;
}
