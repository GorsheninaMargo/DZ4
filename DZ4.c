#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *file1;
    FILE *file2;
    file1 = fopen("graph1.dot", "w");
    file2 = fopen("graph2.dot", "w");
    fprintf(file1, "graph g {\n");
    fprintf(file2, "graph g {\n");
    int v_count = 0;
    printf("Kol-vo vershin = : ");
    scanf("%d", &v_count);
    for(int i = 0; i < v_count; ++i){
        fprintf(file1, "%d;\n", i + 1);
        fprintf(file2, "%d;\n", i + 1);
    }
    printf ("Enter matrix:\n");
    int *v_arr[v_count];
    for(int i = 0; i < v_count; ++i){
        v_arr[i] = (int*)malloc(v_count * sizeof(int));
        for(int j = 0; j < v_count; ++j){
            scanf("%d", &v_arr[i][j]);
            if (j >= i){
                int sup = v_arr[i][j];
                while(sup > 0){
                    fprintf(file1, "%d -- %d;\n", i + 1, j + 1);
                    sup--;
                }
            }
        }
    }
    fprintf(file1, "}\n");
    fclose(file1);

    int v1 = 0, v2 = 0;
    printf("Enter vershiny, megdu kotorimy nado delete rebro.\n");
    printf("Vershina 1:");
    scanf("%d", &v1);
    printf("Vershina 2:");
    scanf("%d", &v2);
    v1--;
    v2--;
    if (v_arr[v1][v2] == 0 || v_arr[v2][v1] == 0){
        printf("There is no specified edge in the graph\n");
        return 1;
    }
    v_arr[v1][v2]--;
    v_arr[v2][v1]--;

    for(int i = 0; i < v_count; ++i){
        for(int j = i; j < v_count; ++j){
            int sup = v_arr[i][j];
            while(sup > 0){
                fprintf(file2, "%d -- %d;\n", i + 1, j + 1);
                sup--;
            }
        }
    }
    fprintf(file2, "}\n");
    fclose(file2);

    int rebra[v_count][2], m=0;
    for (int i = 0; i < v_count; ++i) rebra[i][0] = i + 1;
    for(int i = 0; i < v_count; ++i){
        rebra[i][1] = 0;
        for(int j = 0; j < v_count; ++j){
            rebra[i][1] += v_arr[i][j];
            if (rebra[i][1] >= m) m = rebra[i][1];
        }
    }
    for(int i = 0; i <= m; ++i)
    for(int j = 0; j < v_count; ++j)
    if (rebra[j][1] == i) printf ("Vershina %d, reber %d\n", rebra[j][0], rebra[j][1]);
    for(int i = 0; i < v_count; ++i) free(v_arr[i]);

    system("dot -Tpng graph1.dot -o graph1.png");
    system("graph1.png");
    system("dot -Tpng graph2.dot -o graph2.png");
    system("graph2.png");
    return 0;
}
