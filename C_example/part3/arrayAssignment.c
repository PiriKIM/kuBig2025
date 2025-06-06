#include <stdio.h>

int main(void)
{
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[5];

    // nums2 = nums1; 불가능.
    for(int i = 0; i < 5; i++)
    {
        nums2[i] = nums1[i];
    }
    printf("nums1 의 주소값 : %p\n", nums1);
    printf("nums2 의 주소값 : %p\n", nums2);

    //서로 독립적인 메모리이다.
    nums2[3] = 13;
    //shallow copy
    int *nums3;
    nums3 = nums1;
    printf("nums3 의 주소값 : %p\n", nums3);
    nums3[2] = 23;
    for(int i = 0; i < 5; i++)
    {
        printf("nums1 %d : %d\t\n", i ,nums1[i]);
        printf("nums2 %d : %d\t\n", i ,nums2[i]);
        printf("nums3 %d : %d\t\n", i ,nums3[i]);
    }

    return 0;
}