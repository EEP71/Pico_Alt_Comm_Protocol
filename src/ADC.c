#include <stdio.h>
#include <pico/stdlib.h>

#include <hardware/adc.h>
#include <hardware/dma.h>

#include "ADC.h"
#include "Globals.h"

// dma_channel_config cfg;
// uint dma_chan;
// uint64_t start_time;
// uint64_t end_time;
// int capture_depth = DEFAULT_CAPTURE_DEPTH;
// int clock_divide =  DEFAULT_CLOCK_DEVIDE;
// uint16_t capture_buf[HIGHEST_CAPTURE_DEPTH];

// void init_adc(){
//     gpio_init(LED_PIN);
//     gpio_set_dir(LED_PIN, GPIO_OUT);
//     // Init GPIO for analogue use: hi-Z, no pulls, disable digital input buffer.
//     adc_gpio_init(26 + CAPTURE_CHANNEL);
//     adc_init();
//     adc_select_input(CAPTURE_CHANNEL);
//     adc_fifo_setup(
//         true,    // Write each completed conversion to the sample FIFO
//         true,    // Enable DMA data request (DREQ)
//         1,       // DREQ (and IRQ) asserted when at least 1 sample present
//         true,
//         false     // Shift each sample to 8 bits when pushing to FIFO
//     );

//     // Divisor of 0 -> full speed. Free-running capture with the divider is
//     // equivalent to pressing the ADC_CS_START_ONCE button once per `div + 1`
//     // cycles (div not necessarily an integer). Each conversion takes 96
//     // cycles, so in general you want a divider of 0 (hold down the button
//     // continuously) or > 95 (take samples less frequently than 96 cycle
//     // intervals). This is all timed by the 48 MHz ADC clock.
//     adc_set_clkdiv(clock_divide);
//     sleep_ms(1000);
//     calculate_freq_per_bin();
// }

// void init_dma(){
//     printf("Arming DMA\n");

//     // Set up the DMA to start transferring data as soon as it appears in FIFO
//     dma_chan = dma_claim_unused_channel(true);
//     cfg = dma_channel_get_default_config(dma_chan);

//     // Reading from constant address, writing to incrementing byte addresses
//     channel_config_set_transfer_data_size(&cfg, DMA_SIZE_16);
//     channel_config_set_read_increment(&cfg, false);
//     channel_config_set_write_increment(&cfg, true);

//     // Pace transfers based on availability of ADC samples
//     channel_config_set_dreq(&cfg, DREQ_ADC);

//     dma_channel_configure(
//         dma_chan,       // dmachann
//         &cfg,           // ptr
//         capture_buf,    // dst
//         &adc_hw->fifo,  // src
//         capture_depth,  // transfer count
//         true            // start immediately
//     );
// }

// uint16_t *adc_capture()
// {
//     dma_channel_configure(dma_chan, &cfg,
//         capture_buf,    // dst
//         &adc_hw->fifo,  // src
//         capture_depth,  // transfer count
//         true            // start immediately
//     );
//     adc_run(true);
//     start_time = time_us_64();
//     gpio_put(LED_PIN, 1);
//     dma_channel_wait_for_finish_blocking(dma_chan);
//     gpio_put(LED_PIN, 0);
//     end_time = time_us_64();
//     adc_run(false);
//     adc_fifo_drain();
//     return capture_buf;
// }

// void print_samples(){
//     // Print samples to stdout so you can display them in pyplot, excel, matlab
//     for (int i = 0; i < capture_depth; ++i) {
//         printf("%hu,", capture_buf[i]);
//     }
//     printf("\n");
// }

// void change_capture_depth(int depth){
//     capture_depth = depth;
//     calculate_freq_per_bin();
//     update_fft_alloc();
// }

// void change_clock_divide(int devide){
//     clock_divide = devide;
//     adc_set_clkdiv(clock_divide);
//     calculate_freq_per_bin();
// }

// void print_sample_rate(){
//       uint64_t time_diff_us = end_time-start_time;
//       float sample_time = time_diff_us/1e6;
//       printf("us: %llu | Total Time: %f s\n", time_diff_us, sample_time);
//       printf("Sample Rate: %0.1f Hz\n", capture_depth/(sample_time));
// }