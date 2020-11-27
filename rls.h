#ifndef RLS_H
#define RLS_H

#include "rls_port.h"

/* 该模块需要支持动态数组申请 */

typedef struct
{
    uint16_t    rowsize;
    uint16_t    colsize;
    float       *pdata;
}matrix_fp32_t;

typedef matrix_fp32_t RLS_MATRIX;

/* RLS算法控制器 */
typedef struct 
{
    int             count;
    int             size;       /*! 系统阶数*/
    float           lambda;     /*! 遗忘因子*/
    float           y;          /*! 系统输出采样*/  
    RLS_MATRIX*       x;        /*! 系统输入采样*/
    RLS_MATRIX*       x_T;        /*! 系统输入采样*/
    RLS_MATRIX*       w;        /*! 待估计的权重参数*/   
    RLS_MATRIX*       w_T;        /*! 待估计的权重参数*/   
    RLS_MATRIX*       P;       /*! 辅助参数，应该是一个二维数组?*/
    RLS_MATRIX*       alpha;
    RLS_MATRIX*       k;

    RLS_MATRIX      quanzhong;  /*todo : 权重表*/
}rls_t;

int rls_init(rls_t *rls, int size);

int rls_calc(rls_t *rls, float *new_x, float *new_y);

#endif



