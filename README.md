# Домашнее задание №4
## Условие:
Удалить заданное ребро и в модифицированном графе отсортировать вершины по возростанию степени вершины.
### Выполнение
Проверка на ребра:
```
for(int i = 0; i < v_count; ++i){
        v_arr[i] = (int*)malloc(v_count * sizeof(int));
        for(int j = 0; j < v_count; ++j){
            scanf("%d", &v_arr[i][j]);
            if (j >= i){
                int sup = v_arr[i][j];
                while(sup > 0){
                    fprintf(file1, "%d -- %d;\n", i + 1, j + 1);
                    sup--;
```
Вводим вершины, м ежду которыми ходим удалить ребра
```
int v1 = 0, v2 = 0;
    printf("Enter vershiny, megdu kotorimy nado delete rebro.\n");
    printf("Vershina 1:");
    scanf("%d", &v1);
    printf("Vershina 2:");
    scanf("%d", &v2);
    v1--;
    v2--;
```
Проверка на наличие ребер
```
if (v_arr[v1][v2] == 0 || v_arr[v2][v1] == 0){
        printf("There is no specified edge in the graph\n");
        return 1;
```
Сортируем по возрастанию степени вершин
```
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
```
![graph2](https://user-images.githubusercontent.com/91198767/144578695-45e46004-42e0-4c15-ab8f-64cd91b67785.png)
