#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    int *p;

    p = nums;

    printf("nums : %p\n", p);
    printf("*p : %d\n", *p);
    printf("*(p + 1) : %d\n", *(p + 1));

    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[5];

    // nums2 = nums1;
    for (int i = 0; i < 5; ++i)
    {
        nums2[i] = nums1[i];
    }

    printf("nums2 : ");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    int nums3[] = {1, 2, 3, 4, 5};
    int nums4[] = {1, 2, 3, 4, 5};

    if (nums3 == nums4) {
        printf("nums3 and nums4 are equal\n");
    } else {
        printf("nums3 and nums4 are not equal\n");
    }

    int i;
    for (i = 0; i < 5; ++i)
    {
        if (nums3[i] != nums4[i])
            break;
    }

    if (i == 5) {
        printf("nums3 and nums4 are equal\n");
    } else {
        printf("nums3 and nums4 are not equal\n");
    }

    return 0;
}


/*
int main(void)
{
    int iArr[10];
    char cArr[10];
    
    for (int i = 0; i < 10; ++i)
    {
        if (cArr[i] == '\0')
        cArr[i] = 'N';
        printf("i = %d, c = %c\n", iArr[i], cArr[i]);
    }

    return 0;
}
*/