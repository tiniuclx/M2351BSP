/**************************************************************************//**
 * @file     GPIO.h
 * @version  V3.0
 * @brief    M2351 series General Purpose I/O (GPIO) driver header file
 *
 * @note
 * Copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C"
{
#endif


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup GPIO_Driver GPIO Driver
  @{
*/

/** @addtogroup GPIO_EXPORTED_CONSTANTS GPIO Exported Constants
  @{
*/

#define GPIO_PIN_MAX            16UL /*!< Specify Maximum Pins of Each GPIO Port */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO_MODE Constant Definitions                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_MODE_INPUT          0x0UL /*!< Input Mode */
#define GPIO_MODE_OUTPUT         0x1UL /*!< Output Mode */
#define GPIO_MODE_OPEN_DRAIN     0x2UL /*!< Open-Drain Mode */
#define GPIO_MODE_QUASI          0x3UL /*!< Quasi-bidirectional Mode */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Interrupt Type Constant Definitions                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INT_RISING         0x00010000UL /*!< Interrupt enable by Input Rising Edge */
#define GPIO_INT_FALLING        0x00000001UL /*!< Interrupt enable by Input Falling Edge */
#define GPIO_INT_BOTH_EDGE      0x00010001UL /*!< Interrupt enable by both Rising Edge and Falling Edge */
#define GPIO_INT_HIGH           0x01010000UL /*!< Interrupt enable by Level-High */
#define GPIO_INT_LOW            0x01000001UL /*!< Interrupt enable by Level-Level */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO_INTTYPE Constant Definitions                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INTTYPE_EDGE           0UL /*!< GPIO_INTTYPE Setting for Edge Trigger Mode */
#define GPIO_INTTYPE_LEVEL          1UL /*!< GPIO_INTTYPE Setting for Edge Level Mode */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Slew Rate Type Constant Definitions                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_SLEWCTL_NORMAL         0x0UL           /*!< GPIO slew setting for normal Mode */
#define GPIO_SLEWCTL_HIGH           0x1UL           /*!< GPIO slew setting for high Mode */
#define GPIO_SLEWCTL_FAST           0x2UL           /*!< GPIO slew setting for fast Mode */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Pull-up And Pull-down Type Constant Definitions                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_PUSEL_DISABLE          0x0UL           /*!< GPIO PUSEL setting for Disable Mode */
#define GPIO_PUSEL_PULL_UP          0x1UL           /*!< GPIO PUSEL setting for Pull-up Mode */
#define GPIO_PUSEL_PULL_DOWN        0x2UL           /*!< GPIO PUSEL setting for Pull-down Mode */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO_DBCTL Constant Definitions                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_DBCTL_ICLK_ON            0x00000020UL /*!< GPIO_DBCTL setting for all IO pins edge detection circuit is always active after reset */
#define GPIO_DBCTL_ICLK_OFF           0x00000000UL /*!< GPIO_DBCTL setting for edge detection circuit is active only if IO pin corresponding GPIOx_IEN bit is set to 1 */

#define GPIO_DBCTL_DBCLKSRC_LIRC      0x00000010UL /*!< GPIO_DBCTL setting for de-bounce counter clock source is the internal 10 kHz */
#define GPIO_DBCTL_DBCLKSRC_HCLK      0x00000000UL /*!< GPIO_DBCTL setting for de-bounce counter clock source is the HCLK */

#define GPIO_DBCTL_DBCLKSEL_1         0x00000000UL /*!< GPIO_DBCTL setting for sampling cycle = 1 clocks */
#define GPIO_DBCTL_DBCLKSEL_2         0x00000001UL /*!< GPIO_DBCTL setting for sampling cycle = 2 clocks */
#define GPIO_DBCTL_DBCLKSEL_4         0x00000002UL /*!< GPIO_DBCTL setting for sampling cycle = 4 clocks */
#define GPIO_DBCTL_DBCLKSEL_8         0x00000003UL /*!< GPIO_DBCTL setting for sampling cycle = 8 clocks */
#define GPIO_DBCTL_DBCLKSEL_16        0x00000004UL /*!< GPIO_DBCTL setting for sampling cycle = 16 clocks */
#define GPIO_DBCTL_DBCLKSEL_32        0x00000005UL /*!< GPIO_DBCTL setting for sampling cycle = 32 clocks */
#define GPIO_DBCTL_DBCLKSEL_64        0x00000006UL /*!< GPIO_DBCTL setting for sampling cycle = 64 clocks */
#define GPIO_DBCTL_DBCLKSEL_128       0x00000007UL /*!< GPIO_DBCTL setting for sampling cycle = 128 clocks */
#define GPIO_DBCTL_DBCLKSEL_256       0x00000008UL /*!< GPIO_DBCTL setting for sampling cycle = 256 clocks */
#define GPIO_DBCTL_DBCLKSEL_512       0x00000009UL /*!< GPIO_DBCTL setting for sampling cycle = 512 clocks */
#define GPIO_DBCTL_DBCLKSEL_1024      0x0000000AUL /*!< GPIO_DBCTL setting for sampling cycle = 1024 clocks */
#define GPIO_DBCTL_DBCLKSEL_2048      0x0000000BUL /*!< GPIO_DBCTL setting for sampling cycle = 2048 clocks */
#define GPIO_DBCTL_DBCLKSEL_4096      0x0000000CUL /*!< GPIO_DBCTL setting for sampling cycle = 4096 clocks */
#define GPIO_DBCTL_DBCLKSEL_8192      0x0000000DUL /*!< GPIO_DBCTL setting for sampling cycle = 8192 clocks */
#define GPIO_DBCTL_DBCLKSEL_16384     0x0000000EUL /*!< GPIO_DBCTL setting for sampling cycle = 16384 clocks */
#define GPIO_DBCTL_DBCLKSEL_32768     0x0000000FUL /*!< GPIO_DBCTL setting for sampling cycle = 32768 clocks */


/** Define GPIO Pin Data Input/Output. It could be used to control each I/O pin by pin address mapping.
 *  Example 1:
 *
 *      PA0 = 1;
 *
 *  It is used to set PA.0 to high;
 *
 *  Example 2:
 *
 *      if (PA0)
 *          PA0 = 0;
 *
 *  If PA.0 pin status is high, then set PA.0 data output to low.
 */
#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT0 )
# define PA_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PA_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PA0             PA_PIN_DATA(0, 0 ) /*!< Specify PA.0 Pin Data Input/Output */
#define PA1             PA_PIN_DATA(0, 1 ) /*!< Specify PA.1 Pin Data Input/Output */
#define PA2             PA_PIN_DATA(0, 2 ) /*!< Specify PA.2 Pin Data Input/Output */
#define PA3             PA_PIN_DATA(0, 3 ) /*!< Specify PA.3 Pin Data Input/Output */
#define PA4             PA_PIN_DATA(0, 4 ) /*!< Specify PA.4 Pin Data Input/Output */
#define PA5             PA_PIN_DATA(0, 5 ) /*!< Specify PA.5 Pin Data Input/Output */
#define PA6             PA_PIN_DATA(0, 6 ) /*!< Specify PA.6 Pin Data Input/Output */
#define PA7             PA_PIN_DATA(0, 7 ) /*!< Specify PA.7 Pin Data Input/Output */
#define PA8             PA_PIN_DATA(0, 8 ) /*!< Specify PA.8 Pin Data Input/Output */
#define PA9             PA_PIN_DATA(0, 9 ) /*!< Specify PA.9 Pin Data Input/Output */
#define PA10            PA_PIN_DATA(0, 10) /*!< Specify PA.10 Pin Data Input/Output */
#define PA11            PA_PIN_DATA(0, 11) /*!< Specify PA.11 Pin Data Input/Output */
#define PA12            PA_PIN_DATA(0, 12) /*!< Specify PA.12 Pin Data Input/Output */
#define PA13            PA_PIN_DATA(0, 13) /*!< Specify PA.13 Pin Data Input/Output */
#define PA14            PA_PIN_DATA(0, 14) /*!< Specify PA.14 Pin Data Input/Output */
#define PA15            PA_PIN_DATA(0, 15) /*!< Specify PA.15 Pin Data Input/Output */

#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT1 )
# define PB_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PB_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PB0             PB_PIN_DATA(1, 0 ) /*!< Specify PB.0 Pin Data Input/Output */
#define PB1             PB_PIN_DATA(1, 1 ) /*!< Specify PB.1 Pin Data Input/Output */
#define PB2             PB_PIN_DATA(1, 2 ) /*!< Specify PB.2 Pin Data Input/Output */
#define PB3             PB_PIN_DATA(1, 3 ) /*!< Specify PB.3 Pin Data Input/Output */
#define PB4             PB_PIN_DATA(1, 4 ) /*!< Specify PB.4 Pin Data Input/Output */
#define PB5             PB_PIN_DATA(1, 5 ) /*!< Specify PB.5 Pin Data Input/Output */
#define PB6             PB_PIN_DATA(1, 6 ) /*!< Specify PB.6 Pin Data Input/Output */
#define PB7             PB_PIN_DATA(1, 7 ) /*!< Specify PB.7 Pin Data Input/Output */
#define PB8             PB_PIN_DATA(1, 8 ) /*!< Specify PB.8 Pin Data Input/Output */
#define PB9             PB_PIN_DATA(1, 9 ) /*!< Specify PB.9 Pin Data Input/Output */
#define PB10            PB_PIN_DATA(1, 10) /*!< Specify PB.10 Pin Data Input/Output */
#define PB11            PB_PIN_DATA(1, 11) /*!< Specify PB.11 Pin Data Input/Output */
#define PB12            PB_PIN_DATA(1, 12) /*!< Specify PB.12 Pin Data Input/Output */
#define PB13            PB_PIN_DATA(1, 13) /*!< Specify PB.13 Pin Data Input/Output */
#define PB14            PB_PIN_DATA(1, 14) /*!< Specify PB.14 Pin Data Input/Output */
#define PB15            PB_PIN_DATA(1, 15) /*!< Specify PB.15 Pin Data Input/Output */

#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT2 )
# define PC_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PC_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PC0             PC_PIN_DATA(2, 0 ) /*!< Specify PC.0 Pin Data Input/Output */
#define PC1             PC_PIN_DATA(2, 1 ) /*!< Specify PC.1 Pin Data Input/Output */
#define PC2             PC_PIN_DATA(2, 2 ) /*!< Specify PC.2 Pin Data Input/Output */
#define PC3             PC_PIN_DATA(2, 3 ) /*!< Specify PC.3 Pin Data Input/Output */
#define PC4             PC_PIN_DATA(2, 4 ) /*!< Specify PC.4 Pin Data Input/Output */
#define PC5             PC_PIN_DATA(2, 5 ) /*!< Specify PC.5 Pin Data Input/Output */
#define PC6             PC_PIN_DATA(2, 6 ) /*!< Specify PC.6 Pin Data Input/Output */
#define PC7             PC_PIN_DATA(2, 7 ) /*!< Specify PC.7 Pin Data Input/Output */
#define PC8             PC_PIN_DATA(2, 8 ) /*!< Specify PC.8 Pin Data Input/Output */
#define PC9             PC_PIN_DATA(2, 9 ) /*!< Specify PC.9 Pin Data Input/Output */
#define PC10            PC_PIN_DATA(2, 10) /*!< Specify PC.10 Pin Data Input/Output */
#define PC11            PC_PIN_DATA(2, 11) /*!< Specify PC.11 Pin Data Input/Output */
#define PC12            PC_PIN_DATA(2, 12) /*!< Specify PC.12 Pin Data Input/Output */
#define PC13            PC_PIN_DATA(2, 13) /*!< Specify PC.13 Pin Data Input/Output */

#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT3 )
# define PD_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PD_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PD0             PD_PIN_DATA(3, 0 ) /*!< Specify PD.0 Pin Data Input/Output */
#define PD1             PD_PIN_DATA(3, 1 ) /*!< Specify PD.1 Pin Data Input/Output */
#define PD2             PD_PIN_DATA(3, 2 ) /*!< Specify PD.2 Pin Data Input/Output */
#define PD3             PD_PIN_DATA(3, 3 ) /*!< Specify PD.3 Pin Data Input/Output */
#define PD4             PD_PIN_DATA(3, 4 ) /*!< Specify PD.4 Pin Data Input/Output */
#define PD5             PD_PIN_DATA(3, 5 ) /*!< Specify PD.5 Pin Data Input/Output */
#define PD6             PD_PIN_DATA(3, 6 ) /*!< Specify PD.6 Pin Data Input/Output */
#define PD7             PD_PIN_DATA(3, 7 ) /*!< Specify PD.7 Pin Data Input/Output */
#define PD8             PD_PIN_DATA(3, 8 ) /*!< Specify PD.8 Pin Data Input/Output */
#define PD9             PD_PIN_DATA(3, 9 ) /*!< Specify PD.9 Pin Data Input/Output */
#define PD10            PD_PIN_DATA(3, 10) /*!< Specify PD.10 Pin Data Input/Output */
#define PD11            PD_PIN_DATA(3, 11) /*!< Specify PD.11 Pin Data Input/Output */
#define PD12            PD_PIN_DATA(3, 12) /*!< Specify PD.12 Pin Data Input/Output */
#define PD13            PD_PIN_DATA(3, 13) /*!< Specify PD.13 Pin Data Input/Output */
#define PD14            PD_PIN_DATA(3, 14) /*!< Specify PD.14 Pin Data Input/Output */

#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT4 )
# define PE_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PE_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PE0             PE_PIN_DATA(4, 0 ) /*!< Specify PE.0 Pin Data Input/Output */
#define PE1             PE_PIN_DATA(4, 1 ) /*!< Specify PE.1 Pin Data Input/Output */
#define PE2             PE_PIN_DATA(4, 2 ) /*!< Specify PE.2 Pin Data Input/Output */
#define PE3             PE_PIN_DATA(4, 3 ) /*!< Specify PE.3 Pin Data Input/Output */
#define PE4             PE_PIN_DATA(4, 4 ) /*!< Specify PE.4 Pin Data Input/Output */
#define PE5             PE_PIN_DATA(4, 5 ) /*!< Specify PE.5 Pin Data Input/Output */
#define PE6             PE_PIN_DATA(4, 6 ) /*!< Specify PE.6 Pin Data Input/Output */
#define PE7             PE_PIN_DATA(4, 7 ) /*!< Specify PE.7 Pin Data Input/Output */
#define PE8             PE_PIN_DATA(4, 8 ) /*!< Specify PE.8 Pin Data Input/Output */
#define PE9             PE_PIN_DATA(4, 9 ) /*!< Specify PE.9 Pin Data Input/Output */
#define PE10            PE_PIN_DATA(4, 10) /*!< Specify PE.10 Pin Data Input/Output */
#define PE11            PE_PIN_DATA(4, 11) /*!< Specify PE.11 Pin Data Input/Output */
#define PE12            PE_PIN_DATA(4, 12) /*!< Specify PE.12 Pin Data Input/Output */
#define PE13            PE_PIN_DATA(4, 13) /*!< Specify PE.13 Pin Data Input/Output */
#define PE14            PE_PIN_DATA(4, 14) /*!< Specify PE.14 Pin Data Input/Output */
#define PE15            PE_PIN_DATA(4, 15) /*!< Specify PE.15 Pin Data Input/Output */

#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT5 )
# define PF_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PF_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PF0             PF_PIN_DATA(5, 0 ) /*!< Specify PF.0 Pin Data Input/Output */
#define PF1             PF_PIN_DATA(5, 1 ) /*!< Specify PF.1 Pin Data Input/Output */
#define PF2             PF_PIN_DATA(5, 2 ) /*!< Specify PF.2 Pin Data Input/Output */
#define PF3             PF_PIN_DATA(5, 3 ) /*!< Specify PF.3 Pin Data Input/Output */
#define PF4             PF_PIN_DATA(5, 4 ) /*!< Specify PF.4 Pin Data Input/Output */
#define PF5             PF_PIN_DATA(5, 5 ) /*!< Specify PF.5 Pin Data Input/Output */
#define PF6             PF_PIN_DATA(5, 6 ) /*!< Specify PF.6 Pin Data Input/Output */
#define PF7             PF_PIN_DATA(5, 7 ) /*!< Specify PF.7 Pin Data Input/Output */
#define PF8             PF_PIN_DATA(5, 8 ) /*!< Specify PF.8 Pin Data Input/Output */
#define PF9             PF_PIN_DATA(5, 9 ) /*!< Specify PF.9 Pin Data Input/Output */
#define PF10            PF_PIN_DATA(5, 10) /*!< Specify PF.10 Pin Data Input/Output */
#define PF11            PF_PIN_DATA(5, 11) /*!< Specify PF.11 Pin Data Input/Output */

#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT6 )
# define PG_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PG_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PG2             PG_PIN_DATA(6, 2 ) /*!< Specify PG.2 Pin Data Input/Output */
#define PG3             PG_PIN_DATA(6, 3 ) /*!< Specify PG.3 Pin Data Input/Output */
#define PG4             PG_PIN_DATA(6, 4 ) /*!< Specify PG.4 Pin Data Input/Output */
#define PG9             PG_PIN_DATA(6, 9 ) /*!< Specify PG.9 Pin Data Input/Output */
#define PG10            PG_PIN_DATA(6, 10) /*!< Specify PG.10 Pin Data Input/Output */
#define PG11            PG_PIN_DATA(6, 11) /*!< Specify PG.11 Pin Data Input/Output */
#define PG12            PG_PIN_DATA(6, 12) /*!< Specify PG.12 Pin Data Input/Output */
#define PG13            PG_PIN_DATA(6, 13) /*!< Specify PG.13 Pin Data Input/Output */
#define PG14            PG_PIN_DATA(6, 14) /*!< Specify PG.14 Pin Data Input/Output */
#define PG15            PG_PIN_DATA(6, 15) /*!< Specify PG.15 Pin Data Input/Output */

#if defined (SCU_INIT_IONSSET_VAL) && (SCU_INIT_IONSSET_VAL & BIT7 )
# define PH_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#else
# define PH_PIN_DATA(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#endif
#define PH4             PH_PIN_DATA(7, 4 ) /*!< Specify PH.4 Pin Data Input/Output */
#define PH5             PH_PIN_DATA(7, 5 ) /*!< Specify PH.5 Pin Data Input/Output */
#define PH6             PH_PIN_DATA(7, 6 ) /*!< Specify PH.6 Pin Data Input/Output */
#define PH7             PH_PIN_DATA(7, 7 ) /*!< Specify PH.7 Pin Data Input/Output */
#define PH8             PH_PIN_DATA(7, 8 ) /*!< Specify PH.8 Pin Data Input/Output */
#define PH9             PH_PIN_DATA(7, 9 ) /*!< Specify PH.9 Pin Data Input/Output */
#define PH10            PH_PIN_DATA(7, 10) /*!< Specify PH.10 Pin Data Input/Output */
#define PH11            PH_PIN_DATA(7, 11) /*!< Specify PH.11 Pin Data Input/Output */

/* GPIO bit definitions for secure */
#define GPIO_PIN_DATA_S(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#define PA0_S            GPIO_PIN_DATA_S(0, 0 ) /*!< Specify PA.0 Pin Data Input/Output */
#define PA1_S            GPIO_PIN_DATA_S(0, 1 ) /*!< Specify PA.1 Pin Data Input/Output */
#define PA2_S            GPIO_PIN_DATA_S(0, 2 ) /*!< Specify PA.2 Pin Data Input/Output */
#define PA3_S            GPIO_PIN_DATA_S(0, 3 ) /*!< Specify PA.3 Pin Data Input/Output */
#define PA4_S            GPIO_PIN_DATA_S(0, 4 ) /*!< Specify PA.4 Pin Data Input/Output */
#define PA5_S            GPIO_PIN_DATA_S(0, 5 ) /*!< Specify PA.5 Pin Data Input/Output */
#define PA6_S            GPIO_PIN_DATA_S(0, 6 ) /*!< Specify PA.6 Pin Data Input/Output */
#define PA7_S            GPIO_PIN_DATA_S(0, 7 ) /*!< Specify PA.7 Pin Data Input/Output */
#define PA8_S            GPIO_PIN_DATA_S(0, 8 ) /*!< Specify PA.8 Pin Data Input/Output */
#define PA9_S            GPIO_PIN_DATA_S(0, 9 ) /*!< Specify PA.9 Pin Data Input/Output */
#define PA10_S           GPIO_PIN_DATA_S(0, 10) /*!< Specify PA.10 Pin Data Input/Output */
#define PA11_S           GPIO_PIN_DATA_S(0, 11) /*!< Specify PA.11 Pin Data Input/Output */
#define PA12_S           GPIO_PIN_DATA_S(0, 12) /*!< Specify PA.12 Pin Data Input/Output */
#define PA13_S           GPIO_PIN_DATA_S(0, 13) /*!< Specify PA.13 Pin Data Input/Output */
#define PA14_S           GPIO_PIN_DATA_S(0, 14) /*!< Specify PA.14 Pin Data Input/Output */
#define PA15_S           GPIO_PIN_DATA_S(0, 15) /*!< Specify PA.15 Pin Data Input/Output */
#define PB0_S            GPIO_PIN_DATA_S(1, 0 ) /*!< Specify PB.0 Pin Data Input/Output */
#define PB1_S            GPIO_PIN_DATA_S(1, 1 ) /*!< Specify PB.1 Pin Data Input/Output */
#define PB2_S            GPIO_PIN_DATA_S(1, 2 ) /*!< Specify PB.2 Pin Data Input/Output */
#define PB3_S            GPIO_PIN_DATA_S(1, 3 ) /*!< Specify PB.3 Pin Data Input/Output */
#define PB4_S            GPIO_PIN_DATA_S(1, 4 ) /*!< Specify PB.4 Pin Data Input/Output */
#define PB5_S            GPIO_PIN_DATA_S(1, 5 ) /*!< Specify PB.5 Pin Data Input/Output */
#define PB6_S            GPIO_PIN_DATA_S(1, 6 ) /*!< Specify PB.6 Pin Data Input/Output */
#define PB7_S            GPIO_PIN_DATA_S(1, 7 ) /*!< Specify PB.7 Pin Data Input/Output */
#define PB8_S            GPIO_PIN_DATA_S(1, 8 ) /*!< Specify PB.8 Pin Data Input/Output */
#define PB9_S            GPIO_PIN_DATA_S(1, 9 ) /*!< Specify PB.9 Pin Data Input/Output */
#define PB10_S           GPIO_PIN_DATA_S(1, 10) /*!< Specify PB.10 Pin Data Input/Output */
#define PB11_S           GPIO_PIN_DATA_S(1, 11) /*!< Specify PB.11 Pin Data Input/Output */
#define PB12_S           GPIO_PIN_DATA_S(1, 12) /*!< Specify PB.12 Pin Data Input/Output */
#define PB13_S           GPIO_PIN_DATA_S(1, 13) /*!< Specify PB.13 Pin Data Input/Output */
#define PB14_S           GPIO_PIN_DATA_S(1, 14) /*!< Specify PB.14 Pin Data Input/Output */
#define PB15_S           GPIO_PIN_DATA_S(1, 15) /*!< Specify PB.15 Pin Data Input/Output */
#define PC0_S            GPIO_PIN_DATA_S(2, 0 ) /*!< Specify PC.0 Pin Data Input/Output */
#define PC1_S            GPIO_PIN_DATA_S(2, 1 ) /*!< Specify PC.1 Pin Data Input/Output */
#define PC2_S            GPIO_PIN_DATA_S(2, 2 ) /*!< Specify PC.2 Pin Data Input/Output */
#define PC3_S            GPIO_PIN_DATA_S(2, 3 ) /*!< Specify PC.3 Pin Data Input/Output */
#define PC4_S            GPIO_PIN_DATA_S(2, 4 ) /*!< Specify PC.4 Pin Data Input/Output */
#define PC5_S            GPIO_PIN_DATA_S(2, 5 ) /*!< Specify PC.5 Pin Data Input/Output */
#define PC6_S            GPIO_PIN_DATA_S(2, 6 ) /*!< Specify PC.6 Pin Data Input/Output */
#define PC7_S            GPIO_PIN_DATA_S(2, 7 ) /*!< Specify PC.7 Pin Data Input/Output */
#define PC8_S            GPIO_PIN_DATA_S(2, 8 ) /*!< Specify PC.8 Pin Data Input/Output */
#define PC9_S            GPIO_PIN_DATA_S(2, 9 ) /*!< Specify PC.9 Pin Data Input/Output */
#define PC10_S           GPIO_PIN_DATA_S(2, 10) /*!< Specify PC.10 Pin Data Input/Output */
#define PC11_S           GPIO_PIN_DATA_S(2, 11) /*!< Specify PC.11 Pin Data Input/Output */
#define PC12_S           GPIO_PIN_DATA_S(2, 12) /*!< Specify PC.12 Pin Data Input/Output */
#define PC13_S           GPIO_PIN_DATA_S(2, 13) /*!< Specify PC.13 Pin Data Input/Output */
#define PD0_S            GPIO_PIN_DATA_S(3, 0 ) /*!< Specify PD.0 Pin Data Input/Output */
#define PD1_S            GPIO_PIN_DATA_S(3, 1 ) /*!< Specify PD.1 Pin Data Input/Output */
#define PD2_S            GPIO_PIN_DATA_S(3, 2 ) /*!< Specify PD.2 Pin Data Input/Output */
#define PD3_S            GPIO_PIN_DATA_S(3, 3 ) /*!< Specify PD.3 Pin Data Input/Output */
#define PD4_S            GPIO_PIN_DATA_S(3, 4 ) /*!< Specify PD.4 Pin Data Input/Output */
#define PD5_S            GPIO_PIN_DATA_S(3, 5 ) /*!< Specify PD.5 Pin Data Input/Output */
#define PD6_S            GPIO_PIN_DATA_S(3, 6 ) /*!< Specify PD.6 Pin Data Input/Output */
#define PD7_S            GPIO_PIN_DATA_S(3, 7 ) /*!< Specify PD.7 Pin Data Input/Output */
#define PD8_S            GPIO_PIN_DATA_S(3, 8 ) /*!< Specify PD.8 Pin Data Input/Output */
#define PD9_S            GPIO_PIN_DATA_S(3, 9 ) /*!< Specify PD.9 Pin Data Input/Output */
#define PD10_S           GPIO_PIN_DATA_S(3, 10) /*!< Specify PD.10 Pin Data Input/Output */
#define PD11_S           GPIO_PIN_DATA_S(3, 11) /*!< Specify PD.11 Pin Data Input/Output */
#define PD12_S           GPIO_PIN_DATA_S(3, 12) /*!< Specify PD.12 Pin Data Input/Output */
#define PD13_S           GPIO_PIN_DATA_S(3, 13) /*!< Specify PD.13 Pin Data Input/Output */
#define PD14_S           GPIO_PIN_DATA_S(3, 14) /*!< Specify PD.14 Pin Data Input/Output */
#define PE0_S            GPIO_PIN_DATA_S(4, 0 ) /*!< Specify PE.0 Pin Data Input/Output */
#define PE1_S            GPIO_PIN_DATA_S(4, 1 ) /*!< Specify PE.1 Pin Data Input/Output */
#define PE2_S            GPIO_PIN_DATA_S(4, 2 ) /*!< Specify PE.2 Pin Data Input/Output */
#define PE3_S            GPIO_PIN_DATA_S(4, 3 ) /*!< Specify PE.3 Pin Data Input/Output */
#define PE4_S            GPIO_PIN_DATA_S(4, 4 ) /*!< Specify PE.4 Pin Data Input/Output */
#define PE5_S            GPIO_PIN_DATA_S(4, 5 ) /*!< Specify PE.5 Pin Data Input/Output */
#define PE6_S            GPIO_PIN_DATA_S(4, 6 ) /*!< Specify PE.6 Pin Data Input/Output */
#define PE7_S            GPIO_PIN_DATA_S(4, 7 ) /*!< Specify PE.7 Pin Data Input/Output */
#define PE8_S            GPIO_PIN_DATA_S(4, 8 ) /*!< Specify PE.8 Pin Data Input/Output */
#define PE9_S            GPIO_PIN_DATA_S(4, 9 ) /*!< Specify PE.9 Pin Data Input/Output */
#define PE10_S           GPIO_PIN_DATA_S(4, 10) /*!< Specify PE.10 Pin Data Input/Output */
#define PE11_S           GPIO_PIN_DATA_S(4, 11) /*!< Specify PE.11 Pin Data Input/Output */
#define PE12_S           GPIO_PIN_DATA_S(4, 12) /*!< Specify PE.12 Pin Data Input/Output */
#define PE13_S           GPIO_PIN_DATA_S(4, 13) /*!< Specify PE.13 Pin Data Input/Output */
#define PE14_S           GPIO_PIN_DATA_S(4, 14) /*!< Specify PE.14 Pin Data Input/Output */
#define PE15_S           GPIO_PIN_DATA_S(4, 15) /*!< Specify PE.15 Pin Data Input/Output */
#define PF0_S            GPIO_PIN_DATA_S(5, 0 ) /*!< Specify PF.0 Pin Data Input/Output */
#define PF1_S            GPIO_PIN_DATA_S(5, 1 ) /*!< Specify PF.1 Pin Data Input/Output */
#define PF2_S            GPIO_PIN_DATA_S(5, 2 ) /*!< Specify PF.2 Pin Data Input/Output */
#define PF3_S            GPIO_PIN_DATA_S(5, 3 ) /*!< Specify PF.3 Pin Data Input/Output */
#define PF4_S            GPIO_PIN_DATA_S(5, 4 ) /*!< Specify PF.4 Pin Data Input/Output */
#define PF5_S            GPIO_PIN_DATA_S(5, 5 ) /*!< Specify PF.5 Pin Data Input/Output */
#define PF6_S            GPIO_PIN_DATA_S(5, 6 ) /*!< Specify PF.6 Pin Data Input/Output */
#define PF7_S            GPIO_PIN_DATA_S(5, 7 ) /*!< Specify PF.7 Pin Data Input/Output */
#define PF8_S            GPIO_PIN_DATA_S(5, 8 ) /*!< Specify PF.8 Pin Data Input/Output */
#define PF9_S            GPIO_PIN_DATA_S(5, 9 ) /*!< Specify PF.9 Pin Data Input/Output */
#define PF10_S           GPIO_PIN_DATA_S(5, 10) /*!< Specify PF.10 Pin Data Input/Output */
#define PF11_S           GPIO_PIN_DATA_S(5, 11) /*!< Specify PF.11 Pin Data Input/Output */
#define PG2_S            GPIO_PIN_DATA_S(6, 2 ) /*!< Specify PG.2 Pin Data Input/Output */
#define PG3_S            GPIO_PIN_DATA_S(6, 3 ) /*!< Specify PG.3 Pin Data Input/Output */
#define PG4_S            GPIO_PIN_DATA_S(6, 4 ) /*!< Specify PG.4 Pin Data Input/Output */
#define PG9_S            GPIO_PIN_DATA_S(6, 9 ) /*!< Specify PG.9 Pin Data Input/Output */
#define PG10_S           GPIO_PIN_DATA_S(6, 10) /*!< Specify PG.10 Pin Data Input/Output */
#define PG11_S           GPIO_PIN_DATA_S(6, 11) /*!< Specify PG.11 Pin Data Input/Output */
#define PG12_S           GPIO_PIN_DATA_S(6, 12) /*!< Specify PG.12 Pin Data Input/Output */
#define PG13_S           GPIO_PIN_DATA_S(6, 13) /*!< Specify PG.13 Pin Data Input/Output */
#define PG14_S           GPIO_PIN_DATA_S(6, 14) /*!< Specify PG.14 Pin Data Input/Output */
#define PG15_S           GPIO_PIN_DATA_S(6, 15) /*!< Specify PG.15 Pin Data Input/Output */
#define PH4_S            GPIO_PIN_DATA_S(7, 4 ) /*!< Specify PH.4 Pin Data Input/Output */
#define PH5_S            GPIO_PIN_DATA_S(7, 5 ) /*!< Specify PH.5 Pin Data Input/Output */
#define PH6_S            GPIO_PIN_DATA_S(7, 6 ) /*!< Specify PH.6 Pin Data Input/Output */
#define PH7_S            GPIO_PIN_DATA_S(7, 7 ) /*!< Specify PH.7 Pin Data Input/Output */
#define PH8_S            GPIO_PIN_DATA_S(7, 8 ) /*!< Specify PH.8 Pin Data Input/Output */
#define PH9_S            GPIO_PIN_DATA_S(7, 9 ) /*!< Specify PH.9 Pin Data Input/Output */
#define PH10_S           GPIO_PIN_DATA_S(7, 10) /*!< Specify PH.10 Pin Data Input/Output */
#define PH11_S           GPIO_PIN_DATA_S(7, 11) /*!< Specify PH.11 Pin Data Input/Output */

/* GPIO bit definitions for non-secure */
#define GPIO_PIN_DATA_NS(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#define PA0_NS            GPIO_PIN_DATA_NS(0, 0 ) /*!< Specify PA.0 Pin Data Input/Output */
#define PA1_NS            GPIO_PIN_DATA_NS(0, 1 ) /*!< Specify PA.1 Pin Data Input/Output */
#define PA2_NS            GPIO_PIN_DATA_NS(0, 2 ) /*!< Specify PA.2 Pin Data Input/Output */
#define PA3_NS            GPIO_PIN_DATA_NS(0, 3 ) /*!< Specify PA.3 Pin Data Input/Output */
#define PA4_NS            GPIO_PIN_DATA_NS(0, 4 ) /*!< Specify PA.4 Pin Data Input/Output */
#define PA5_NS            GPIO_PIN_DATA_NS(0, 5 ) /*!< Specify PA.5 Pin Data Input/Output */
#define PA6_NS            GPIO_PIN_DATA_NS(0, 6 ) /*!< Specify PA.6 Pin Data Input/Output */
#define PA7_NS            GPIO_PIN_DATA_NS(0, 7 ) /*!< Specify PA.7 Pin Data Input/Output */
#define PA8_NS            GPIO_PIN_DATA_NS(0, 8 ) /*!< Specify PA.8 Pin Data Input/Output */
#define PA9_NS            GPIO_PIN_DATA_NS(0, 9 ) /*!< Specify PA.9 Pin Data Input/Output */
#define PA10_NS           GPIO_PIN_DATA_NS(0, 10) /*!< Specify PA.10 Pin Data Input/Output */
#define PA11_NS           GPIO_PIN_DATA_NS(0, 11) /*!< Specify PA.11 Pin Data Input/Output */
#define PA12_NS           GPIO_PIN_DATA_NS(0, 12) /*!< Specify PA.12 Pin Data Input/Output */
#define PA13_NS           GPIO_PIN_DATA_NS(0, 13) /*!< Specify PA.13 Pin Data Input/Output */
#define PA14_NS           GPIO_PIN_DATA_NS(0, 14) /*!< Specify PA.14 Pin Data Input/Output */
#define PA15_NS           GPIO_PIN_DATA_NS(0, 15) /*!< Specify PA.15 Pin Data Input/Output */
#define PB0_NS            GPIO_PIN_DATA_NS(1, 0 ) /*!< Specify PB.0 Pin Data Input/Output */
#define PB1_NS            GPIO_PIN_DATA_NS(1, 1 ) /*!< Specify PB.1 Pin Data Input/Output */
#define PB2_NS            GPIO_PIN_DATA_NS(1, 2 ) /*!< Specify PB.2 Pin Data Input/Output */
#define PB3_NS            GPIO_PIN_DATA_NS(1, 3 ) /*!< Specify PB.3 Pin Data Input/Output */
#define PB4_NS            GPIO_PIN_DATA_NS(1, 4 ) /*!< Specify PB.4 Pin Data Input/Output */
#define PB5_NS            GPIO_PIN_DATA_NS(1, 5 ) /*!< Specify PB.5 Pin Data Input/Output */
#define PB6_NS            GPIO_PIN_DATA_NS(1, 6 ) /*!< Specify PB.6 Pin Data Input/Output */
#define PB7_NS            GPIO_PIN_DATA_NS(1, 7 ) /*!< Specify PB.7 Pin Data Input/Output */
#define PB8_NS            GPIO_PIN_DATA_NS(1, 8 ) /*!< Specify PB.8 Pin Data Input/Output */
#define PB9_NS            GPIO_PIN_DATA_NS(1, 9 ) /*!< Specify PB.9 Pin Data Input/Output */
#define PB10_NS           GPIO_PIN_DATA_NS(1, 10) /*!< Specify PB.10 Pin Data Input/Output */
#define PB11_NS           GPIO_PIN_DATA_NS(1, 11) /*!< Specify PB.11 Pin Data Input/Output */
#define PB12_NS           GPIO_PIN_DATA_NS(1, 12) /*!< Specify PB.12 Pin Data Input/Output */
#define PB13_NS           GPIO_PIN_DATA_NS(1, 13) /*!< Specify PB.13 Pin Data Input/Output */
#define PB14_NS           GPIO_PIN_DATA_NS(1, 14) /*!< Specify PB.14 Pin Data Input/Output */
#define PB15_NS           GPIO_PIN_DATA_NS(1, 15) /*!< Specify PB.15 Pin Data Input/Output */
#define PC0_NS            GPIO_PIN_DATA_NS(2, 0 ) /*!< Specify PC.0 Pin Data Input/Output */
#define PC1_NS            GPIO_PIN_DATA_NS(2, 1 ) /*!< Specify PC.1 Pin Data Input/Output */
#define PC2_NS            GPIO_PIN_DATA_NS(2, 2 ) /*!< Specify PC.2 Pin Data Input/Output */
#define PC3_NS            GPIO_PIN_DATA_NS(2, 3 ) /*!< Specify PC.3 Pin Data Input/Output */
#define PC4_NS            GPIO_PIN_DATA_NS(2, 4 ) /*!< Specify PC.4 Pin Data Input/Output */
#define PC5_NS            GPIO_PIN_DATA_NS(2, 5 ) /*!< Specify PC.5 Pin Data Input/Output */
#define PC6_NS            GPIO_PIN_DATA_NS(2, 6 ) /*!< Specify PC.6 Pin Data Input/Output */
#define PC7_NS            GPIO_PIN_DATA_NS(2, 7 ) /*!< Specify PC.7 Pin Data Input/Output */
#define PC8_NS            GPIO_PIN_DATA_NS(2, 8 ) /*!< Specify PC.8 Pin Data Input/Output */
#define PC9_NS            GPIO_PIN_DATA_NS(2, 9 ) /*!< Specify PC.9 Pin Data Input/Output */
#define PC10_NS           GPIO_PIN_DATA_NS(2, 10) /*!< Specify PC.10 Pin Data Input/Output */
#define PC11_NS           GPIO_PIN_DATA_NS(2, 11) /*!< Specify PC.11 Pin Data Input/Output */
#define PC12_NS           GPIO_PIN_DATA_NS(2, 12) /*!< Specify PC.12 Pin Data Input/Output */
#define PC13_NS           GPIO_PIN_DATA_NS(2, 13) /*!< Specify PC.13 Pin Data Input/Output */
#define PD0_NS            GPIO_PIN_DATA_NS(3, 0 ) /*!< Specify PD.0 Pin Data Input/Output */
#define PD1_NS            GPIO_PIN_DATA_NS(3, 1 ) /*!< Specify PD.1 Pin Data Input/Output */
#define PD2_NS            GPIO_PIN_DATA_NS(3, 2 ) /*!< Specify PD.2 Pin Data Input/Output */
#define PD3_NS            GPIO_PIN_DATA_NS(3, 3 ) /*!< Specify PD.3 Pin Data Input/Output */
#define PD4_NS            GPIO_PIN_DATA_NS(3, 4 ) /*!< Specify PD.4 Pin Data Input/Output */
#define PD5_NS            GPIO_PIN_DATA_NS(3, 5 ) /*!< Specify PD.5 Pin Data Input/Output */
#define PD6_NS            GPIO_PIN_DATA_NS(3, 6 ) /*!< Specify PD.6 Pin Data Input/Output */
#define PD7_NS            GPIO_PIN_DATA_NS(3, 7 ) /*!< Specify PD.7 Pin Data Input/Output */
#define PD8_NS            GPIO_PIN_DATA_NS(3, 8 ) /*!< Specify PD.8 Pin Data Input/Output */
#define PD9_NS            GPIO_PIN_DATA_NS(3, 9 ) /*!< Specify PD.9 Pin Data Input/Output */
#define PD10_NS           GPIO_PIN_DATA_NS(3, 10) /*!< Specify PD.10 Pin Data Input/Output */
#define PD11_NS           GPIO_PIN_DATA_NS(3, 11) /*!< Specify PD.11 Pin Data Input/Output */
#define PD12_NS           GPIO_PIN_DATA_NS(3, 12) /*!< Specify PD.12 Pin Data Input/Output */
#define PD13_NS           GPIO_PIN_DATA_NS(3, 13) /*!< Specify PD.13 Pin Data Input/Output */
#define PD14_NS           GPIO_PIN_DATA_NS(3, 14) /*!< Specify PD.14 Pin Data Input/Output */
#define PE0_NS            GPIO_PIN_DATA_NS(4, 0 ) /*!< Specify PE.0 Pin Data Input/Output */
#define PE1_NS            GPIO_PIN_DATA_NS(4, 1 ) /*!< Specify PE.1 Pin Data Input/Output */
#define PE2_NS            GPIO_PIN_DATA_NS(4, 2 ) /*!< Specify PE.2 Pin Data Input/Output */
#define PE3_NS            GPIO_PIN_DATA_NS(4, 3 ) /*!< Specify PE.3 Pin Data Input/Output */
#define PE4_NS            GPIO_PIN_DATA_NS(4, 4 ) /*!< Specify PE.4 Pin Data Input/Output */
#define PE5_NS            GPIO_PIN_DATA_NS(4, 5 ) /*!< Specify PE.5 Pin Data Input/Output */
#define PE6_NS            GPIO_PIN_DATA_NS(4, 6 ) /*!< Specify PE.6 Pin Data Input/Output */
#define PE7_NS            GPIO_PIN_DATA_NS(4, 7 ) /*!< Specify PE.7 Pin Data Input/Output */
#define PE8_NS            GPIO_PIN_DATA_NS(4, 8 ) /*!< Specify PE.8 Pin Data Input/Output */
#define PE9_NS            GPIO_PIN_DATA_NS(4, 9 ) /*!< Specify PE.9 Pin Data Input/Output */
#define PE10_NS           GPIO_PIN_DATA_NS(4, 10) /*!< Specify PE.10 Pin Data Input/Output */
#define PE11_NS           GPIO_PIN_DATA_NS(4, 11) /*!< Specify PE.11 Pin Data Input/Output */
#define PE12_NS           GPIO_PIN_DATA_NS(4, 12) /*!< Specify PE.12 Pin Data Input/Output */
#define PE13_NS           GPIO_PIN_DATA_NS(4, 13) /*!< Specify PE.13 Pin Data Input/Output */
#define PE14_NS           GPIO_PIN_DATA_NS(4, 14) /*!< Specify PE.14 Pin Data Input/Output */
#define PE15_NS           GPIO_PIN_DATA_NS(4, 15) /*!< Specify PE.15 Pin Data Input/Output */
#define PF0_NS            GPIO_PIN_DATA_NS(5, 0 ) /*!< Specify PF.0 Pin Data Input/Output */
#define PF1_NS            GPIO_PIN_DATA_NS(5, 1 ) /*!< Specify PF.1 Pin Data Input/Output */
#define PF2_NS            GPIO_PIN_DATA_NS(5, 2 ) /*!< Specify PF.2 Pin Data Input/Output */
#define PF3_NS            GPIO_PIN_DATA_NS(5, 3 ) /*!< Specify PF.3 Pin Data Input/Output */
#define PF4_NS            GPIO_PIN_DATA_NS(5, 4 ) /*!< Specify PF.4 Pin Data Input/Output */
#define PF5_NS            GPIO_PIN_DATA_NS(5, 5 ) /*!< Specify PF.5 Pin Data Input/Output */
#define PF6_NS            GPIO_PIN_DATA_NS(5, 6 ) /*!< Specify PF.6 Pin Data Input/Output */
#define PF7_NS            GPIO_PIN_DATA_NS(5, 7 ) /*!< Specify PF.7 Pin Data Input/Output */
#define PF8_NS            GPIO_PIN_DATA_NS(5, 8 ) /*!< Specify PF.8 Pin Data Input/Output */
#define PF9_NS            GPIO_PIN_DATA_NS(5, 9 ) /*!< Specify PF.9 Pin Data Input/Output */
#define PF10_NS           GPIO_PIN_DATA_NS(5, 10) /*!< Specify PF.10 Pin Data Input/Output */
#define PF11_NS           GPIO_PIN_DATA_NS(5, 11) /*!< Specify PF.11 Pin Data Input/Output */
#define PG2_NS            GPIO_PIN_DATA_NS(6, 2 ) /*!< Specify PG.2 Pin Data Input/Output */
#define PG3_NS            GPIO_PIN_DATA_NS(6, 3 ) /*!< Specify PG.3 Pin Data Input/Output */
#define PG4_NS            GPIO_PIN_DATA_NS(6, 4 ) /*!< Specify PG.4 Pin Data Input/Output */
#define PG9_NS            GPIO_PIN_DATA_NS(6, 9 ) /*!< Specify PG.9 Pin Data Input/Output */
#define PG10_NS           GPIO_PIN_DATA_NS(6, 10) /*!< Specify PG.10 Pin Data Input/Output */
#define PG11_NS           GPIO_PIN_DATA_NS(6, 11) /*!< Specify PG.11 Pin Data Input/Output */
#define PG12_NS           GPIO_PIN_DATA_NS(6, 12) /*!< Specify PG.12 Pin Data Input/Output */
#define PG13_NS           GPIO_PIN_DATA_NS(6, 13) /*!< Specify PG.13 Pin Data Input/Output */
#define PG14_NS           GPIO_PIN_DATA_NS(6, 14) /*!< Specify PG.14 Pin Data Input/Output */
#define PG15_NS           GPIO_PIN_DATA_NS(6, 15) /*!< Specify PG.15 Pin Data Input/Output */
#define PH4_NS            GPIO_PIN_DATA_NS(7, 4 ) /*!< Specify PH.4 Pin Data Input/Output */
#define PH5_NS            GPIO_PIN_DATA_NS(7, 5 ) /*!< Specify PH.5 Pin Data Input/Output */
#define PH6_NS            GPIO_PIN_DATA_NS(7, 6 ) /*!< Specify PH.6 Pin Data Input/Output */
#define PH7_NS            GPIO_PIN_DATA_NS(7, 7 ) /*!< Specify PH.7 Pin Data Input/Output */
#define PH8_NS            GPIO_PIN_DATA_NS(7, 8 ) /*!< Specify PH.8 Pin Data Input/Output */
#define PH9_NS            GPIO_PIN_DATA_NS(7, 9 ) /*!< Specify PH.9 Pin Data Input/Output */
#define PH10_NS           GPIO_PIN_DATA_NS(7, 10) /*!< Specify PH.10 Pin Data Input/Output */
#define PH11_NS           GPIO_PIN_DATA_NS(7, 11) /*!< Specify PH.11 Pin Data Input/Output */

/*@}*/ /* end of group GPIO_EXPORTED_CONSTANTS */


/** @addtogroup GPIO_EXPORTED_FUNCTIONS GPIO Exported Functions
  @{
*/

/**
 * @brief       Clear GPIO Pin Interrupt Flag
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB, PC, PD and PF. \n
 *                          It could be BIT0 ~ BIT13 for PE. \n
 *                          It could be BIT1 ~ BIT5, BIT7 ~ BIT12 for PG.
 *
 * @return      None
 *
 * @details     Clear the interrupt status of specified GPIO pin.
 */
#define GPIO_CLR_INT_FLAG(port, u32PinMask)         ((port)->INTSRC = (u32PinMask))

/**
 * @brief       Disable Pin De-bounce Function
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB and PE. \n
 *                          It could be BIT0 ~ BIT13 for PC. \n
 *                          It could be BIT0 ~ BIT14 for PD. \n
 *                          It could be BIT0 ~ BIT11 for PF. \n
 *                          It could be BIT2 ~ BIT3, BIT9 ~ BIT15 for PG. \n
 *                          It could be BIT4 ~ BIT11 for PH.
 *
 * @return      None
 *
 * @details     Disable the interrupt de-bounce function of specified GPIO pin.
 */
#define GPIO_DISABLE_DEBOUNCE(port, u32PinMask)     ((port)->DBEN &= ~(u32PinMask))

/**
 * @brief       Enable Pin De-bounce Function
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB and PE. \n
 *                          It could be BIT0 ~ BIT13 for PC. \n
 *                          It could be BIT0 ~ BIT14 for PD. \n
 *                          It could be BIT0 ~ BIT11 for PF. \n
 *                          It could be BIT2 ~ BIT3, BIT9 ~ BIT15 for PG. \n
 *                          It could be BIT4 ~ BIT11 for PH.
 * @return      None
 *
 * @details     Enable the interrupt de-bounce function of specified GPIO pin.
 */
#define GPIO_ENABLE_DEBOUNCE(port, u32PinMask)      ((port)->DBEN |= (u32PinMask))

/**
 * @brief       Disable I/O Digital Input Path
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB and PE. \n
 *                          It could be BIT0 ~ BIT13 for PC. \n
 *                          It could be BIT0 ~ BIT14 for PD. \n
 *                          It could be BIT0 ~ BIT11 for PF. \n
 *                          It could be BIT2 ~ BIT3, BIT9 ~ BIT15 for PG. \n
 *                          It could be BIT4 ~ BIT11 for PH.
 *
 * @return      None
 *
 * @details     Disable I/O digital input path of specified GPIO pin.
 */
#define GPIO_DISABLE_DIGITAL_PATH(port, u32PinMask) ((port)->DINOFF |= ((u32PinMask)<<16))

/**
 * @brief       Enable I/O Digital Input Path
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB and PE. \n
 *                          It could be BIT0 ~ BIT13 for PC. \n
 *                          It could be BIT0 ~ BIT14 for PD. \n
 *                          It could be BIT0 ~ BIT11 for PF. \n
 *                          It could be BIT2 ~ BIT3, BIT9 ~ BIT15 for PG. \n
 *                          It could be BIT4 ~ BIT11 for PH.
 *
 * @return      None
 *
 * @details     Enable I/O digital input path of specified GPIO pin.
 */
#define GPIO_ENABLE_DIGITAL_PATH(port, u32PinMask)  ((port)->DINOFF &= ~((u32PinMask)<<16))

/**
 * @brief       Disable I/O DOUT mask
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB and PE. \n
 *                          It could be BIT0 ~ BIT13 for PC. \n
 *                          It could be BIT0 ~ BIT14 for PD. \n
 *                          It could be BIT0 ~ BIT11 for PF. \n
 *                          It could be BIT2 ~ BIT3, BIT9 ~ BIT15 for PG. \n
 *                          It could be BIT4 ~ BIT11 for PH.
 *
 * @return      None
 *
 * @details     Disable I/O DOUT mask of specified GPIO pin.
 */
#define GPIO_DISABLE_DOUT_MASK(port, u32PinMask)    ((port)->DATMSK &= ~(u32PinMask))

/**
 * @brief       Enable I/O DOUT mask
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB and PE. \n
 *                          It could be BIT0 ~ BIT13 for PC. \n
 *                          It could be BIT0 ~ BIT14 for PD. \n
 *                          It could be BIT0 ~ BIT11 for PF. \n
 *                          It could be BIT2 ~ BIT3, BIT9 ~ BIT15 for PG. \n
 *                          It could be BIT4 ~ BIT11 for PH.
 *
 * @return      None
 *
 * @details     Enable I/O DOUT mask of specified GPIO pin.
 */
#define GPIO_ENABLE_DOUT_MASK(port, u32PinMask) ((port)->DATMSK |= (u32PinMask))

/**
 * @brief       Get GPIO Pin Interrupt Flag
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. \n
 *                          It could be BIT0 ~ BIT15 for PA, PB and PE. \n
 *                          It could be BIT0 ~ BIT13 for PC. \n
 *                          It could be BIT0 ~ BIT14 for PD. \n
 *                          It could be BIT0 ~ BIT11 for PF. \n
 *                          It could be BIT2 ~ BIT3, BIT9 ~ BIT15 for PG. \n
 *                          It could be BIT4 ~ BIT11 for PH.
 *
 * @retval      0           No interrupt at specified GPIO pin
 * @retval      1           The specified GPIO pin generate an interrupt
 *
 * @details     Get the interrupt status of specified GPIO pin.
 */
#define GPIO_GET_INT_FLAG(port, u32PinMask)     ((port)->INTSRC & (u32PinMask))

/**
 * @brief       Set De-bounce Sampling Cycle Time
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32ClkSrc   The de-bounce counter clock source. It could be GPIO_DBCTL_DBCLKSRC_HCLK or GPIO_DBCTL_DBCLKSRC_LIRC.
 * @param[in]   u32ClkSel   The de-bounce sampling cycle selection. It could be
 *                            - \ref GPIO_DBCTL_DBCLKSEL_1
 *                            - \ref GPIO_DBCTL_DBCLKSEL_2
 *                            - \ref GPIO_DBCTL_DBCLKSEL_4
 *                            - \ref GPIO_DBCTL_DBCLKSEL_8
 *                            - \ref GPIO_DBCTL_DBCLKSEL_16
 *                            - \ref GPIO_DBCTL_DBCLKSEL_32
 *                            - \ref GPIO_DBCTL_DBCLKSEL_64
 *                            - \ref GPIO_DBCTL_DBCLKSEL_128
 *                            - \ref GPIO_DBCTL_DBCLKSEL_256
 *                            - \ref GPIO_DBCTL_DBCLKSEL_512
 *                            - \ref GPIO_DBCTL_DBCLKSEL_1024
 *                            - \ref GPIO_DBCTL_DBCLKSEL_2048
 *                            - \ref GPIO_DBCTL_DBCLKSEL_4096
 *                            - \ref GPIO_DBCTL_DBCLKSEL_8192
 *                            - \ref GPIO_DBCTL_DBCLKSEL_16384
 *                            - \ref GPIO_DBCTL_DBCLKSEL_32768
 *
 * @return      None
 *
 * @details     Set the interrupt de-bounce sampling cycle time based on the debounce counter clock source. \n
 *              Example: _GPIO_SET_DEBOUNCE_TIME(PA, GPIO_DBCTL_DBCLKSRC_LIRC, GPIO_DBCTL_DBCLKSEL_4). \n
 *              It's meaning the De-debounce counter clock source is internal 10 KHz and sampling cycle selection is 4. \n
 *              Then the target de-bounce sampling cycle time is (4)*(1/(10*1000)) s = 4*0.0001 s = 400 us,
 *              and system will sampling interrupt input once per 400 us.
 */
#define GPIO_SET_DEBOUNCE_TIME(port, u32ClkSrc, u32ClkSel)    ((port)->DBCTL = (GPIO_DBCTL_ICLKON_Msk | (u32ClkSrc) | (u32ClkSel)))

/**
 * @brief       Get GPIO Port IN Data
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 *
 * @return      The specified port data
 *
 * @details     Get the PIN register of specified GPIO port.
 */
#define GPIO_GET_IN_DATA(port)  ((port)->PIN)

/**
 * @brief       Set GPIO Port OUT Data
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32Data     GPIO port data.
 *
 * @return      None
 *
 * @details     Set the Data into specified GPIO port.
 */
#define GPIO_SET_OUT_DATA(port, u32Data)    ((port)->DOUT = (u32Data))

/**
 * @brief       Toggle Specified GPIO pin
 *
 * @param[in]   u32Pin      Pxy
 *
 * @return      None
 *
 * @details     Toggle the specified GPIO pint.
 */
#define GPIO_TOGGLE(u32Pin) ((u32Pin) ^= 1)


/**
 * @brief       Enable External GPIO interrupt
 *
 * @param[in]   port            GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32Pin          The pin of specified GPIO port. \n
 *                              It could be 0 ~ 15 for PA, PB and PE. \n
 *                              It could be 0 ~ 13 for PC GPIO port. \n
 *                              It could be 0 ~ 14 for PD GPIO port. \n
 *                              It could be 0 ~ 11 for PF GPIO port. \n
 *                              It could be 2 ~ 4, 9 ~ 15 for PG GPIO port. \n
 *                              It could be 4 ~ 11 for PH GPIO port.
 * @param[in]   u32IntAttribs   The interrupt attribute of specified GPIO pin. It could be
 *                              - \ref GPIO_INT_RISING
 *                              - \ref GPIO_INT_FALLING
 *                              - \ref GPIO_INT_BOTH_EDGE
 *                              - \ref GPIO_INT_HIGH
 *                              - \ref GPIO_INT_LOW
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
#define GPIO_EnableEINT     GPIO_EnableInt

/**
 * @brief       Disable External GPIO interrupt
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG or PH.
 * @param[in]   u32Pin      The pin of specified GPIO port. \n
 *                          It could be 0 ~ 15 for PA, PB and PE. \n
 *                          It could be 0 ~ 13 for PC GPIO port. \n
 *                          It could be 0 ~ 14 for PD GPIO port. \n
 *                          It could be 0 ~ 11 for PF GPIO port. \n
 *                          It could be 2 ~ 4, 9 ~ 15 for PG GPIO port. \n
 *                          It could be 4 ~ 11 for PH GPIO port.
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
#define GPIO_DisableEINT    GPIO_DisableInt


void GPIO_SetMode(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableInt(GPIO_T *port, uint32_t u32Pin, uint32_t u32IntAttribs);
void GPIO_DisableInt(GPIO_T *port, uint32_t u32Pin);
void GPIO_SetSlewCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_SetPullCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);


/*@}*/ /* end of group GPIO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group GPIO_Driver */

/*@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_H__ */

/*** (C) COPYRIGHT 2016 Nuvoton Technology Corp. ***/
