//#include<stdio.h>
//#include<stdlib.h>
//
//int main() {
//    FILE *fp;
//    char *filepath = "D:\\data.txt";
//    char buf[1024];
//    int e;
//
//    if ((fp = fopen(filepath, "r")) == NULL) {
//        printf("Open file error!");
//        exit(0);
//    }
//
//    while (fgets(buf, 1024, fp)) {
//        //get a whole line string
////        printf("%s", buf);
//        printf("%d\n",atoi(buf));
//    }
//
////    while ((fscanf(fp, "%s", buf)) != EOF) {
////        printf("%s", buf);
////    }
//
////    while (!feof(fp)) {
////        fread(buf, 1, 100, fp);
////        printf("%s\n", buf);
////    }
//    fclose(fp);
//
//}