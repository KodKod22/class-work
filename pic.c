#include<stdio.h>
void DisplayArray2D(char arr[][7]){
    for (int l=0 ;l<7 ; ++l)
{
    for (int col=0 ; col<7 ; ++col)
    printf("%c", arr[l][col]);
    printf("\n");
}
}
void RotateArray2D(char arrRotated[][7],char arrOriginal[][7]){
    
    for (int i = 0; i < 7; i++)
    {
        for(int j = 0; j< 7;j++){
            arrRotated[j][i] = arrOriginal[6-i][j];
        }
    }
    
}
void main(){
char picMirrorF[7][7];
char arr[7][7]={
{ '*',' ',' ',' ',' ',' ',' ',},
{ '*','*',' ',' ',' ',' ',' ',},
{ '*','*','*',' ',' ',' ',' ',},
{ '*','*','*','*','*','*','*',},
{ '*','*','*',' ',' ',' ',' ',},
{ '*','*',' ',' ',' ',' ',' ',},
{ '*',' ',' ',' ',' ',' ',' ',},
};
DisplayArray2D(arr);
RotateArray2D(picMirrorF,arr);
DisplayArray2D(picMirrorF);
RotateArray2D(arr,picMirrorF);
DisplayArray2D(arr);
}