#include <stdio.h>
#include "opencv.h"
// g++ -ggdb `pkg-config --cflags opencv` main.cpp -o main `pkg-config --libs opencv`

//using namespace cv;
#define FILDERNUM 10
#define FILENO 10
#define DEBUG 0

void cal_feature(const char* FileName, int feature_veotors[64])
{
    int i, j, k;
    IplImage* Image = NULL;

    Image = cvLoadImage(FileName, CV_LOAD_IMAGE_GRAYSCALE);

    if (Image == NULL) {
        fprintf(stderr, "Can not load image %s\n", FileName);
        exit(-1);
    }

    BwImage BlockA(Image);

    k = 0;

    for (i = 0; i < Image->height; ++i) {
        for (j = 0; j < Image->width; ++j) {
            k = j + 1;

            if (k < Image->width && BlockA[i][j] != BlockA[i][k]) {
                feature_veotors[i] += 1;
            }

            if (k < Image->width && BlockA[j][i] != BlockA[k][i]) {
                feature_veotors[i + 32] += 1;
            }
        }
    }

#if DEBUG

    for (i = 0; i < Image->height; ++i) {
        for (j = 0; j < Image->width; ++j) {
            printf("%3d ", BlockA[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 64; ++i) {
        printf("%3d", feature_veotors[i]);
    }

    printf("\n");

    cvShowImage("Show Image", Image);
    cv::waitKey();
#endif

    cvReleaseImage(&Image);

}

void stats_features_veotors(int fildernum, int feature_veotors[64],
                            float feature_veotors_table[][64])
{
    int i;

    for (i = 0; i < 64; ++i) {
        feature_veotors_table[fildernum][i] += feature_veotors[i];
    }
}

void features_train()
{
    FILE* pFile;
    char FileName[50];
    float feature_veotors_table[10][64] = {0};
    int i, j;

    for (i = 0; i < FILDERNUM; ++i) {
        for (j = 0; j < FILENO; ++j) {
            int feature_veotors[64] = {0};

            sprintf(FileName, "number1_bmp/%d/%d.bmp", i, j);
            cal_feature(FileName,  feature_veotors);
            stats_features_veotors(i,  feature_veotors, feature_veotors_table);
        }
    }

#if DEBUG
    printf("\n");
#endif

    for (i = 0; i < 10; ++i) {
        sprintf(FileName, "%d.txt", i);
        pFile = fopen(FileName, "w");

        for (j = 0; j < 64; ++j) {
            feature_veotors_table[i][j] /= 10.0;
            fprintf(pFile, "%f\n", feature_veotors_table[i][j]);
#if DEBUG
            printf("%f ", feature_veotors_table[i][j]);
#endif
        }

        fclose(pFile);
#if DEBUG
        printf("\n\n");
#endif
    }
}

void features_train_begin()
{
    FILE* pFile;
    int i, j;
    char FileName[50];
    float feature_veotors_table[10][64] = {0} , value;

    features_train();

#if DEBUG
    printf("\n\n\n\n");

    for (i = 0; i < 10; ++i) {
        sprintf(FileName, "%d.txt", i);
        pFile = fopen(FileName, "r");

        if (!pFile) {
            printf("open file fail...\n");
            exit(1);
        }

        for (j = 0; j < 64; ++j) {
            fscanf(pFile, "%f\n", &value);
            feature_veotors_table[i][j] = value;
            printf("%f ", feature_veotors_table[i][j]);
        }

        printf("\n\n");
        fclose(pFile);
    }

#endif
}

void similar_compare(int feature_veotors[64])
{
    float similar_vectors[10] = {0};
    float value, min_value;
    int i, j, result;
    char FileName[50];
    FILE* pFile;

    for (i = 0; i < 10; ++i) {
        sprintf(FileName, "%d.txt", i);
        pFile = fopen(FileName, "r");

        if (!pFile) {
            printf("open file fail...\n");
            exit(1);
        }

        for (j = 0; j < 64; ++j) {
            fscanf(pFile, "%f\n", &value);
            similar_vectors[i] += (feature_veotors[j] - value) * (feature_veotors[j] -
                                  value);
        }

        similar_vectors[i] = sqrt(similar_vectors[i] / (float)64);
        printf("%f\n", similar_vectors[i]);
        fclose(pFile);
    }

    min_value = similar_vectors[0];

    result = 0;

    for (i = 1; i < 10; ++i) {
        if (similar_vectors[i] < min_value) {
            min_value = similar_vectors[i];
            result = i;
        }
    }

    printf("\ndigital=%d\n", result);

}


int main(int argc, char* argv[])
{
    char FileName[50];
    int i;
    int feature_veotors[64] = {0};

    if (argc >= 2) {
        cal_feature(argv[1],  feature_veotors);

        for (i = 0; i < 64; ++i) {
            printf("%d ", feature_veotors[i]);
        }

        printf("\n");
        similar_compare(feature_veotors);
    } else {
        features_train_begin();
    }

    return 0;
}
