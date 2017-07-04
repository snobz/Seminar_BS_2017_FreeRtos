/* vim: set sw=8 sts=8 noet foldmethod=syntax : */


#include "stm32f4xx_it.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
/* Includes ------------------------------------------------------------------*/
//#include "usbvcp.h"
//#include "stm32f4xx_it.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern PCD_HandleTypeDef hpcd;

/* UART handler declared in "usbd_cdc_interface.c" file */
extern UART_HandleTypeDef UartHandle;

/* TIM handler declared in "usbd_cdc_interface.c" file */
extern TIM_HandleTypeDef TimHandle;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*             Cortex-M4 Processor Exceptions Handlers                        */
/******************************************************************************/


/**
  * @brief  This function handles USB-On-The-Go FS global interrupt request.
  * @param  None
  * @retval None
  */
//#ifdef USE_USB_FS
//void OTG_FS_IRQHandler(void)
//#else
//void OTG_HS_IRQHandler(void)
//#endif
//{
//  HAL_PCD_IRQHandler(&hpcd);
//}

/**
  * @brief  This function handles DMA interrupt request.
  * @param  None
  * @retval None
  */
void USARTx_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(UartHandle.hdmatx);
}

/**
  * @brief  This function handles UART interrupt request.
  * @param  None
  * @retval None
  */
void USARTx_IRQHandler(void)
{
  HAL_UART_IRQHandler(&UartHandle);
}


/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

extern "C" void xPortSysTickHandler(void);

/**
 * @brief   This function handles NMI exception.
 * @param  None
 * @retval None
 */
void NMI_Handler(void) {
}


void prvGetRegistersFromStack( uint32_t *pulFaultStackAddress )
{
    //ErrorHandler::pulFaultStackAddress = pulFaultStackAddress;
    //ErrorHandler::Error_Handler(HARD_FAULT);
}

/**
 * @brief  This function handles Hard Fault exception.
 * @param  None
 * @retval None
 */
__attribute__((naked))
void HardFault_Handler(void) {
//    __asm volatile
//        (
//            " tst lr, #4                                                \n"
//            " ite eq                                                    \n"
//            " mrseq r0, msp                                             \n"
//            " mrsne r0, psp                                             \n"
//            " ldr r1, [r0, #24]                                         \n"
//            " ldr r2, handler2_address_const                            \n"
//            " bx r2                                                     \n"
//            " handler2_address_const: .word prvGetRegistersFromStack    \n"
//        );
//
while (1)
{
}
}

/**
 * @brief  This function handles Memory Manage exception.
 * @param  None
 * @retval None
 */
void MemManage_Handler(void) {
/* Go to infinite loop when Memory Manage exception occurs */
while (1) {
}
}

/**
 * @brief  This function handles Bus Fault exception.
 * @param  None
 * @retval None
 */
void BusFault_Handler(void) {
/* Go to infinite loop when Bus Fault exception occurs */
while (1) {
}
}

/**
 * @brief  This function handles Usage Fault exception.
 * @param  None
 * @retval None
 */
void UsageFault_Handler(void) {
/* Go to infinite loop when Usage Fault exception occurs */
while (1) {
}
}

/**
 * @brief  This function handles SVCall exception.
 * @param  None
 * @retval None
 */
/*
 void SVC_Handler(void)
 {
 }
 */

/**
 * @brief  This function handles Debug Monitor exception.
 * @param  None
 * @retval None
 */
void DebugMon_Handler(void) {
}

/**
 * @brief  This function handles PendSVC exception.
 * @param  None
 * @retval None
 */

 void PendSV_Handler(void)
 {
 }


/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void) {
if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
    xPortSysTickHandler();
}

HAL_IncTick();

}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (CAN), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

///**								// MOD_BORJA
// * EXI2 interrupt handler
// */
//void EXTI2_IRQHandler(void) {
//    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
//}
//
///**
// * EXI2 interrupt handler
// */
//void EXTI3_IRQHandler(void) {
//    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
//}