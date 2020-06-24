#include<stdio.h>

int main(){

int c[20][20]={0},A[20][20],D[20][20],n,e,u,v,w,i,j,k,no_path,a[10];

printf("Enter no of vertices\t");

scanf("%d",&n);

printf("Enter no of edges\t");

scanf("%d",&e);

for(i=0;i<e;i++){

printf("Enter nodes and weight\t");

scanf("%d%d%d",&u,&v,&w);

c[u-1][v-1]=w;

}

for(i=0;i<n;i++)

for(j=0;j<n;j++)

if(c[i][j]==0)

D[i][j]=-1;

else

D[i][j]=i+1;

for(i=0;i<n;i++)

for(j=0;j<n;j++)

if(i!=j && c[i][j]==0)

c[i][j]=999;

for(i=0;i<n;i++)

for(j=0;j<n;j++)

A[i][j]=c[i][j];

for(k=0;k<n;k++)

for(i=0;i<n;i++)

for(j=0;j<n;j++)

if(A[i][j]>(A[i][k]+A[k][j]))

{

A[i][j]=A[i][k]+A[k][j];

D[i][j]=k+1;

}

printf("Length matrix is\n");

for(i=0;i<n;i++){

for(j=0;j<n;j++){

printf("%d\t",A[i][j]);

}

printf("\n");

}

printf("Decision matrix is\n");

for(i=0;i<n;i++){

for(j=0;j<n;j++){

printf("%d\t",D[i][j]);

}

printf("\n");

}

for(i=0;i<n;i++)

for(j=0;j<n;j++)

if(D[i][j]!=-1)

D[i][j]-=1;

printf("Enter no of paths you want\t");

scanf("%d",&no_path);

for(i=0;i<no_path;i++){

printf("Enter node to find path\t");

scanf("%d%d",&u,&v);

k=0;

u--; v--;

j=v;

do{

a[k++]=j+1;

j=D[u][j];

}while(j!=u);

a[k]=u+1;

printf("Cost is %d\t",A[u][v]);

printf("Path is : ");

for(j=k;j>0;j--)

printf("%d-",a[j]);

printf("%d\n",a[0]);

}

return 0;

}
