/*
 * Copyright (c) 2019 Carlo Caione <ccaione@baylibre.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_PL011_PORT0_BASE_ADDRESS	DT_ARM_PL011_9000000_BASE_ADDRESS
#define DT_PL011_PORT0_NAME		DT_ARM_PL011_9000000_LABEL
#define DT_PL011_PORT0_CLOCK_FREQUENCY	DT_ARM_PL011_9000000_CLOCK_FREQUENCY
#define DT_PL011_PORT0_BAUD_RATE	DT_ARM_PL011_9000000_CURRENT_SPEED

#define DT_INST_0_SHARED_IRQ_IRQ_0_SENSE	DT_INST_0_SHARED_IRQ_IRQ_0_FLAGS

#undef DT_INST_0_SHARED_IRQ_IRQ_0
#define DT_INST_0_SHARED_IRQ_IRQ_0	((DT_SHARED_IRQ_SHAREDIRQ0_IRQ_0 + 1) << 8)
