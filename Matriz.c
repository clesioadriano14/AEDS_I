#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, m[3][3], v[3], r[3][3];
    printf("Vetor: ");
    for(i=0;i<3;i++){
        scanf("%d",&v[i]);
    }
    printf("Matriz: ");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&m[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            r[i][j] = v[j] * m[i][j];
        }
    }
    printf("\nResulante:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
}
