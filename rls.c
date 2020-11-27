#include "rls.h"


/* 本模块需要支持动态内存分配 */
int rls_init(rls_t *rls, int size)
{
    rls_malloc(size * sizeof(float));
}


int rls_calc(rls_t *rls, float *new_x, float new_y)
{
    if(rls == NULL)
    {
        return -1;
    }

    matrix_set(rls->x, new_x);

    matrix_trans(rls->x, rls->x_T);

    RLS_MATRIX *pii = matrix_alloc(rls->size, 1);
    RLS_MATRIX *pii_T = matrix_alloc(rls->size, 1);
    RLS_MATRIX *m_tmp_1_1 = matrix_alloc(1, 1);
    RLS_MATRIX *m_tmp_n_1 = matrix_alloc(rls->size, 1);
    RLS_MATRIX *m_tmp_n_n = matrix_alloc(rls->size, rls->size);

    matrix_mul(rls->x_T, rls->P, pii);

    
    matrix(pii, rls->x, m_tmp_1_1);

    float gamma = rls->lambda + m_tmp_1_1->pdata[0];

    matrix_trans(pii, pii_T);
    matrix_scale_mul(pii, rls->k, 1.0f/gamma);

    matrix_mul(rls->w_T, rls->x, m_tmp_1_1);
    rls->alpha->pdata[0] = new_y - m_tmp_1_1->pdata[0];
    
    matrix_mul(rls->k, m_tmp_1_1, m_tmp_n_1);
    matrix_add(rls->w, rls->w, m_tmp_n_1);

    matrix_trans(rls->w, rls->w_T);

    matrix_mul(rls->k, pii, m_tmp_n_n);
    matrix_sub(rls->P, m_tmp_n_n, m_tmp_n_n);
    matrix_scale_mul(m_tmp_n_n, rls->P, 1.0f/rls->lambda);  

    float lamb = rls->lambda;
    float P = rls->P;

    for(int i = 0; i < rls->dim; i++)
    {
        rls->x[i] = new_x[i];
    }
    rls->y = new_y;
    
    
}