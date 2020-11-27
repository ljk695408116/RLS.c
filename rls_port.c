#include "rls_port.h"


int matrix_add(RLS_MATRIX *a, RLS_MATRIX *b, RLS_MATRIX *out)
{

}

int matrix_sub(RLS_MATRIX *a, RLS_MATRIX *b, RLS_MATRIX *out)
{

}


int matrix_mul(RLS_MATRIX *a, RLS_MATRIX *b, RLS_MATRIX *out)
{

}

int matrix_scale_mul(RLS_MATRIX *a, RLS_MATRIX *out, float num)
{

}

int  matrix_trans(RLS_MATRIX *a, RLS_MATRIX *a_T)
{

}

RLS_MATRIX* matrix_alloc(uint32_t rowsize, uint32_t colsize)
{
   RLS_MATRIX* matrix_ptr = rls_malloc(sizeof(RLS_MATRIX));
   if(matrix_ptr == NULL)
   {
       goto _exit;
   }

   matrix_ptr->pdata = rls_malloc(rowsize * colsize * sizeof(float));
   if(matrix_ptr->pdata == NULL)
   {
       goto _matrix_clear;
   }

   matrix_ptr->rowsize = rowsize;
   matrix_ptr->colsize = colsize; 
   
#if 0
    for(int i = 0; i < rowsize * colsize; i++)
    {
        matrix_ptr->pdata[i] = 0.0f;
    }
#endif

   return matrix_ptr;

_matrix_clear:
    rls_free(matrix_ptr);
_exit:
    return NULL;
}

int matrix_set(RLS_MATRIX* matrix_ptr, float *pdata)
{
    if(matrix_ptr == NULL || pdata == NULL )
    {
        return -1;
    }

    for(int i = 0; i < matrix_ptr->rowsize * matrix_ptr->colsize; i++)
    {
        matrix_ptr->pdata[i] = pdata[i];
    }
    return 0;
}

void matrix_free(RLS_MATRIX* matrix_ptr)
{
    rls_free(matrix_ptr->pdata);
    rls_free(matrix_ptr);
}

void *rls_malloc(int size)
{
    
}

void *rls_free(void *ptr)
{
    
}
