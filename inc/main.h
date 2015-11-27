/**
  ******************************************************************************
  * @file    Audio_playback_and_record/inc/main.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-October-2011
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_audio_codec.h"
//#include "stm32f4_discovery_lis302dl.h"
#include <stdio.h>
#include "stm32f4xx_it.h"
#include "waveplayer.h"

#ifdef MEDIA_USB_KEY
 #include "waverecorder.h"
 #include "usb_hcd_int.h"
 #include "usbh_usr.h"
 #include "usbh_core.h"
 #include "usbh_msc_core.h"
 #include "pdm_filter.h"
#endif
 
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Select the media where the Wave file is stored */
#if !defined (MEDIA_IntFLASH) && !defined (MEDIA_USB_KEY) 
 //#define MEDIA_IntFLASH /* Wave file stored in internal flash */
 //#define MEDIA_USB_KEY  /* Wave file stored in USB flash */
#endif

/* Uncomment this define to disable repeat option */
//#define PLAY_REPEAT_OFF

#if defined MEDIA_USB_KEY
// Имена аудифайлов, wav формат, стерео, 8000Гц, 16бит.
  #define WAVE_NAME "0:audio.wav"
  #define WAVE_NAME1 "0:audio1.wav"
  #define WAVE_NAME2 "0:audio2.wav"
  #define WAVE_NAME3 "0:audio3.wav"
  #define WAVE_NAME4 "0:audio4.wav"
  #define REC_WAVE_NAME "0:rec.wav"
 
  #define RAM_BUFFER_SIZE         1500
  // Устанавливаем  максимальное время записи             20 мин.                     
  #define TIME_REC                60000            /*      (default: 30s) */
#endif /* MEDIA_USB_KEY */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);

#endif /* __MAIN_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
