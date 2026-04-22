    /** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
     *   Modul               : 2
     *   Hari dan Tanggal    : Rabu, 22 April 2026
     *   Nama (NIM)          : R. Damar Prawiro Kusumo Sudradjat (13224109)
     *   Nama File           : soal1.c
     *   Deskripsi           : Menghitung statistik array menggunakan fungsi parameter pointer
     * 
     */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void sumout(int *arr[], int N, int *sum);
    void avgout(int N, float *avg, int *sum);
    void maxout(int *arr[], int N, int *max, int *idx);

    int main()
    {
        int N;
        int sum = 0, max, idx;
        float avg;
        char input[100];
        fgets(input, 100, stdin);
        char* tok;
        tok = strtok(input, " ");
        N = atoi(tok);
        int* arr[N];
        
        for (int i = 0; i < N; i++)
        {
            arr[i] = (int *)malloc(sizeof(int));
            tok = strtok(NULL, " ");
            *arr[i] = atoi(tok);
            //printf("%d\n", *arr[i]);
        }
        sumout(arr, N, &sum);
        avgout(N, &avg, &sum);
        maxout(arr, N, &max, &idx);

        printf("SUM %d\n", sum);
        printf("AVG %.2f\n", avg);
        printf("MAX %d\n", max);
        printf("IDX %d\n", idx);

        for (int i = 0; i < N; i++)
        {
            free(arr[i]);
        }
        
        return 0;
    }

    void sumout(int *arr[], int N, int *sum){
        for (int i = 0; i < N; i++)
        {
            *sum += *arr[i];
        }
    }

    void avgout(int N, float *avg, int *sum){
        *avg = (float)*sum / (float)N;
    }

    void maxout(int *arr[], int N, int *max, int *idx){
        *max = *arr[0];
        *idx = 0;
        for (int i = 1; i < N; i++)
        {
            if (*max < *arr[i])
            {
                *max = *arr[i];
                *idx = i;
            }
        }
    }
