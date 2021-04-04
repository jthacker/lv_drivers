/**
 * @file fbdev.h
 *
 */

#ifndef FBDEV_H
#define FBDEV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "../../lv_drv_conf.h"
#endif
#endif

#if USE_FBDEV || USE_BSD_FBDEV

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
/**
 * Initialize the fbdev from the device specified in FBDEV_PATH
 */
void fbdev_init(void);
/**
 * Initialize the fbdev from the specified device, e.g. /dev/fb0
 * @param path path to the framebuffer device
 */
void fbdev_init_with_path(const char * path);
void fbdev_exit(void);
void fbdev_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p);
void fbdev_get_sizes(uint32_t *width, uint32_t *height);
/**
 * Clear the screen by zeroing out the framebuffer.
 * Useful to call after exiting.
 */
void fbdev_clear_screen(lv_disp_drv_t * drv);


/**********************
 *      MACROS
 **********************/

#endif  /*USE_FBDEV*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*FBDEV_H*/
