/**
  ****************************************************************************************************
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
  ****************************************************************************************************
  */
  
#include "svd.h"
#include "fm33fh0xx_fl.h"

/**
  * @brief  SVD Initialization function
  * @param  SVD_MONTIOR_POWER 选择SVD监控电源:
  *           @arg @ref SVD_MONTIOR_VDD 内部电源(VDD)
  *           @arg @ref SVD_MONTIOR_SVS 外部电源(SVS)
  *         u32WarningThreshold 报警阈值档位:
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP0
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP1
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP2
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP3
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP4
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP5
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP6
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP7
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP8
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP9
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP10
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP11
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP12
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP13
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP14
  *           @arg @ref FL_SVD_WARNING_THRESHOLD_GROUP15
  *         u32RevVoltage 参考基准源:
  *           @arg @ref FL_SVD_REFERENCE_1P0V
  *           @arg @ref FL_SVD_REFERENCE_0P95V
  *           @arg @ref FL_SVD_REFERENCE_0P9V
  *         FunMode功能模式：
  *           @arg @ref FL_SVD_Mode_DISABLE           
  *           @arg @ref FL_SVD_Mode_LOWVOLTAGE_WARNING
  *           @arg @ref FL_SVD_Mode_UNDERVOLTAGE_RESET
  * @retval FL_FAIL: 初始化失败
  *         FL_PASS: 初始化成功
  */
FL_ErrorStatus SVD_Init(SVD_MONTIOR_POWER eSVD_MonitroPower, uint32_t u32WarnThreshold, uint32_t u32RevVoltage, uint32_t FunMode)
{
	  uint32_t i = 200UL;
    FL_ErrorStatus status;
    FL_SVD_InitTypeDef SVD_InitStruct = {0};
    
    SVD_InitStruct.referenceVoltage = u32RevVoltage;                  /* 参考电压 */
    SVD_InitStruct.warningThreshold = u32WarnThreshold;               /* 报警阈值 */
    SVD_InitStruct.digitalFilter = FL_ENABLE;                         /* 数字滤波 */
    SVD_InitStruct.workMode = FL_SVD_WORK_MODE_CONTINUOUS;            /* 工作模式 */
    SVD_InitStruct.enablePeriod = FL_SVD_ENABLE_PERIOD_62P5MS;        /* 间歇使能间隔 */
    SVD_InitStruct.SVSChannel = (FL_FunState)(SVD_MONTIOR_SVS == eSVD_MonitroPower);  /* SVS通道选择 */ 
    SVD_InitStruct.funcMode = FunMode;        /* SVD功能选择 */
    SVD_InitStruct.gateCtrl = FL_ENABLE;      /* 门控选择 */
    
    /* 初始化寄存器 */
    status = FL_SVD_Init(SVD, &SVD_InitStruct);
    
    /* SVD开启后到输出稳定建立需等待100us  */
    while(i--) {
			__NOP();
		}

    return status;
}


