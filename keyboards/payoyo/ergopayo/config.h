// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


// Limit the power draw
#define RGBLIGHT_LIMIT_VAL 80  

// Not yet available in `info.json`
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 80
#define RGB_MATRIX_LED_COUNT 2

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
