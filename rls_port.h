#ifndef RLS_PORT_H
#define RLS_PORT_H



#ifndef NULL
#define NULL ((void*)(0))
#endif

/* 该模块需要支持动态数组申请 */
typedef struct
{
    uint16_t    rowsize;
    uint16_t    colsize;
    float       *pdata;
}matrix_fp32_t;

typedef matrix_fp32_t RLS_MATRIX;

int matrix_set(RLS_MATRIX* matrix_ptr, float *pdata);
int matrix_init(RLS_MATRIX* matrix_ptr, float *pdata);
void matrix_free(RLS_MATRIX* matrix_ptr);

int matrix_add(RLS_MATRIX *a, RLS_MATRIX *b, RLS_MATRIX *out);
int matrix_sub(RLS_MATRIX *a, RLS_MATRIX *b, RLS_MATRIX *out);
int matrix_mul(RLS_MATRIX *a, RLS_MATRIX *b, RLS_MATRIX *out);

int matrix_scale_mul(RLS_MATRIX *a, RLS_MATRIX *out, float num);
int  matrix_trans(RLS_MATRIX *a, RLS_MATRIX *a_T)
void *rls_malloc(int size);
void *rls_free(void *ptr);

#endif