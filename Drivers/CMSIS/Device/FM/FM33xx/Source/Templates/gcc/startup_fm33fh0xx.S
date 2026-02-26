/**
  ******************************************************************************
  * @file      startup_fm33fh0xx.S
  * @author
  * @brief     FM33FH0xx devices vector table for GCC toolchain.
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M0+ processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  * @version  V1.1.0
  * @date     13. June 2025
  ******************************************************************************
  * @attention    
  * Copyright 2024 SHANGHAI FUDAN MICROELECTRONICS GROUP CO., LTD.(FUDAN MICRO.)
  *        
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met: 
  *    
  * 1. Redistributions of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  *    
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  *    
  * 3. Neither the name of the copyright holder nor the names of its contributors 
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *    
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS"AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   
  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   
  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
  *
  ******************************************************************************
  */

  .syntax unified
  .cpu cortex-m0plus
  .fpu softvfp
  .thumb

.global  g_pfnVectors
.global  Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word  _sidata
/* start address for the .data section. defined in linker script */
.word  _sdata
/* end address for the .data section. defined in linker script */
.word  _edata
/* start address for the .bss section. defined in linker script */
.word  _sbss
/* end address for the .bss section. defined in linker script */
.word  _ebss

  .section  .text.Reset_Handler
  .weak  Reset_Handler
  .type  Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */

/* Copy the data segment initializers from flash to SRAM */
  movs  r1, #0
  b  LoopCopyDataInit

CopyDataInit:
  ldr  r3, =_sidata
  ldr  r3, [r3, r1]
  str  r3, [r0, r1]
  adds  r1, r1, #4

LoopCopyDataInit:
  ldr  r0, =_sdata
  ldr  r3, =_edata
  adds  r2, r0, r1
  cmp  r2, r3
  bcc  CopyDataInit
  ldr  r2, =_sbss
  b  LoopFillZerobss
/* Zero fill the bss segment. */
FillZerobss:
  movs  r3, #0
  str  r3, [r2]
  adds r2, r2, #4

LoopFillZerobss:
  ldr  r3, = _ebss
  cmp  r2, r3
  bcc  FillZerobss

/* Call the clock system intitialization function.*/
  bl  SystemInit
/* Call static constructors */
  bl __libc_init_array
/* Call the application's entry point.*/
  bl  main

LoopForever:
  b LoopForever

.size  Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
*/
  .section  .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b  Infinite_Loop
  .size  Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex M0.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
  .section  .isr_vector,"a",%progbits
  .type  g_pfnVectors, %object
  .size  g_pfnVectors, .-g_pfnVectors


g_pfnVectors:
  .word  _estack
  .word  Reset_Handler
  .word  NMI_Handler
  .word  HardFault_Handler
  .word  0
  .word  0
  .word  0
  .word  0
  .word  0
  .word  0
  .word  0
  .word  SVC_Handler
  .word  0
  .word  0
  .word  PendSV_Handler
  .word  SysTick_Handler
  /* External Interrupts */
  .word  MUX0_IRQHandler                     
  .word  MUX1_IRQHandler                     
  .word  MUX2_IRQHandler                      
  .word  MUX3_IRQHandler                   
  .word  MUX4_IRQHandler                    
  .word  MUX5_IRQHandler                       
  .word  MUX6_IRQHandler                    
  .word  MUX7_IRQHandler                    
  .word  MUX8_IRQHandler                  
  .word  MUX9_IRQHandler                    
  .word  MUX10_IRQHandler                  
  .word  MUX11_IRQHandler              
  .word  MUX12_IRQHandler                   
  .word  MUX13_IRQHandler                    
  .word  MUX14_IRQHandler                     
  .word  MUX15_IRQHandler                     
  .word  MUX16_IRQHandler                     
  .word  MUX17_IRQHandler                 
  .word  MUX18_IRQHandler                    
  .word  MUX19_IRQHandler                   
  .word  MUX20_IRQHandler             
  .word  MUX21_IRQHandler                      
  .word  MUX22_IRQHandler                    
  .word  MUX23_IRQHandler                  
  .word  MUX24_IRQHandler                   
  .word  MUX25_IRQHandler                     
  .word  MUX26_IRQHandler                     
  .word  MUX27_IRQHandler                    
  .word  MUX28_IRQHandler                     
  .word  MUX29_IRQHandler                  
  .word  MUX30_IRQHandler                
  .word  MUX31_IRQHandler          

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/
   .weak      NMI_Handler
   .thumb_set NMI_Handler,Default_Handler

   .weak      HardFault_Handler
   .thumb_set HardFault_Handler,Default_Handler

   .weak      SVC_Handler
   .thumb_set SVC_Handler,Default_Handler

   .weak      PendSV_Handler
   .thumb_set PendSV_Handler,Default_Handler

   .weak      SysTick_Handler
   .thumb_set SysTick_Handler,Default_Handler




   .weak      MUX0_IRQHandler
   .thumb_set MUX0_IRQHandler,Default_Handler

   .weak      MUX1_IRQHandler
   .thumb_set MUX1_IRQHandler,Default_Handler

   .weak      MUX2_IRQHandler
   .thumb_set MUX2_IRQHandler,Default_Handler

   .weak      MUX3_IRQHandler
   .thumb_set MUX3_IRQHandler,Default_Handler

   .weak      MUX4_IRQHandler
   .thumb_set MUX4_IRQHandler,Default_Handler

   .weak      MUX5_IRQHandler
   .thumb_set MUX5_IRQHandler,Default_Handler

   .weak      MUX6_IRQHandler
   .thumb_set MUX6_IRQHandler,Default_Handler

   .weak      MUX7_IRQHandler
   .thumb_set MUX7_IRQHandler,Default_Handler

   .weak      MUX8_IRQHandler
   .thumb_set MUX8_IRQHandler,Default_Handler

   .weak      MUX9_IRQHandler
   .thumb_set MUX9_IRQHandler,Default_Handler

   .weak      MUX10_IRQHandler
   .thumb_set MUX10_IRQHandler,Default_Handler

   .weak      MUX11_IRQHandler
   .thumb_set MUX11_IRQHandler,Default_Handler

   .weak      MUX12_IRQHandler
   .thumb_set MUX12_IRQHandler,Default_Handler

   .weak      MUX13_IRQHandler
   .thumb_set MUX13_IRQHandler,Default_Handler

   .weak      MUX14_IRQHandler
   .thumb_set MUX14_IRQHandler,Default_Handler

   .weak      MUX15_IRQHandler
   .thumb_set MUX15_IRQHandler,Default_Handler

   .weak      MUX16_IRQHandler
   .thumb_set MUX16_IRQHandler,Default_Handler

   .weak      MUX17_IRQHandler
   .thumb_set MUX17_IRQHandler,Default_Handler

   .weak      MUX18_IRQHandler
   .thumb_set MUX18_IRQHandler,Default_Handler

   .weak      MUX19_IRQHandler
   .thumb_set MUX19_IRQHandler,Default_Handler

   .weak      MUX20_IRQHandler
   .thumb_set MUX20_IRQHandler,Default_Handler

   .weak      MUX21_IRQHandler
   .thumb_set MUX21_IRQHandler,Default_Handler

   .weak      MUX22_IRQHandler
   .thumb_set MUX22_IRQHandler,Default_Handler

   .weak      MUX23_IRQHandler
   .thumb_set MUX23_IRQHandler,Default_Handler

   .weak      MUX24_IRQHandler
   .thumb_set MUX24_IRQHandler,Default_Handler

   .weak      MUX25_IRQHandler
   .thumb_set MUX25_IRQHandler,Default_Handler

   .weak      MUX26_IRQHandler
   .thumb_set MUX26_IRQHandler,Default_Handler

   .weak      MUX27_IRQHandler
   .thumb_set MUX27_IRQHandler,Default_Handler

   .weak      MUX28_IRQHandler
   .thumb_set MUX28_IRQHandler,Default_Handler
   
   .weak      MUX29_IRQHandler
   .thumb_set MUX29_IRQHandler,Default_Handler

   .weak      MUX30_IRQHandler
   .thumb_set MUX30_IRQHandler,Default_Handler
   
   .weak      MUX31_IRQHandler
   .thumb_set MUX31_IRQHandler,Default_Handler

/*****************************END OF FILE**************************************/
