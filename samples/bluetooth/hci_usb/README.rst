.. _bluetooth-hci-usb-sample:

Bluetooth: HCI USB
##################

Overview
********

Make a USB Bluetooth dongle out of Zephyr. Requires USB device support from the
board it runs on (e.g. :ref:`nrf52840dk_nrf52840` supports both BLE and USB).

Requirements
************

* Bluetooth stack running on the host (e.g. BlueZ)
* A board with Bluetooth and USB support in Zephyr

Building and Running
********************
This sample can be found under :zephyr_file:`samples/bluetooth/hci_usb` in the
Zephyr tree.

See :ref:`bluetooth samples section <bluetooth-samples>` for details.

.. note::
   If you want to run this sample on the nRF5340 device (build using
   ``-DBOARD=nrf5340dk_nrf5340_cpuapp`` or
   ``-DBOARD=nrf5340dk_nrf5340_cpuappns``) you must also build
   and program the corresponding sample for the nRF5340 network core:
   :ref:` bluetooth-hci-rpmsg-sample` which implements the Bluetooth
   Low Energy controller.
