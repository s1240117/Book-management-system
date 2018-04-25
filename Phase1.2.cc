
/**
 * @file Phase1.1.cc
 * @brief フェーズ１−2のコードです
 * @author YukiFunayama
 * @date 4/24
 */

#include <iostream>
#include <math.h>
#include <map>
using namespace std;
/**
 * @fn
 * @param (BR1) 引数の説明:ユーザーAの書籍A評価
 * @param (BR2) 引数の説明:ユーザーBの書籍A評価
 * @param (BR3) 引数の説明:ユーザーAの書籍B評価
 * @param (BR4) 引数の説明:ユーザーBの書籍B評価
 * @return ユーザ同士がどの程度似ているかを表す指標score
 * @detail ユークリッド距離による計算を行う
 */
double EuclideanDistance(double BR1,double BR2,double BR3,double BR4){
  double data1 = pow(BR1-BR2,2);
  double data2 = pow(BR3-BR4,2);
  double data = data1+data2;
  double score = sqrt(data);
  score = 1/(score+1);
  return score;
}

int main(){

  int n1,n2;
  int count=0;
  cin >> n1 >> n2;
  double result[n2];
  double data1[n1][n2];
  for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
      cin >> data1[i][j];
    }
  }
  for(int i=1;i<n1;i++){
    double score=0;
    count = 0;
    for(int j=0;j<n2;j++){
      for(int k=1+j;k<n2;k++){
      if(data1[0][j]==-1||data1[i][j]==-1||data1[0][k]==-1||data1[i][k]==-1) continue;
      score = score + EuclideanDistance(data1[0][j],data1[i][j],data1[0][k],data1[i][k]);
      count++;
      }
    }
    result[i+1]=score/count;
  }
  double data2[n1][n2];
  int k=0;
  for(int i=0;i<n2;i++){
    if(data1[0][i] == -1){
      for(int j=1;j<n1;j++){
        //cout << "data1[" << j << "][" << i << "] =" <<data1[j][i] << endl;
        data2[0][k] = i+1; //書籍番号を先頭に保持しておく
        data2[j][k] = data1[j][i];
        //cout << "data2[" << j-1 << "][" << k << "] =" <<data2[j-1][k] << endl;
      }
      k++;
    }
  }
  double S=0,A=0,result2[2][k];
  for(int i=0;i<k;i++){
    S=0,A=0;
    for(int j=1;j<n1;j++){
      if(data2[j][i] != -1){
        S+=result[j+1]*data2[j][i];
        //cout << "result[j+1] = " <<result[j+1] << endl;
        //cout << "data2[j][i] = " << data2[j][i] << endl;
        //cout << "S" << data2[0][i] <<"="<<S<<endl;
        A+=result[j+1];
        //cout << "A" << data2[0][i] <<"="<<A<<endl;
      }
    }
    result2[0][i] = data2[0][i];
    result2[1][i] = S/A;
  }
  //for(int i=0;i<k;i++){
  //cout <<"result2[0][" << i << "] = " << result2[0][i] << endl;
  //cout <<"result2[1][" << i << "] = " << result2[1][i] << endl;
//}
double maxV = -1;
int maxI = -1,c=0;
for(int i=0;i<k;i++){
  for(int j=0;j<k;j++){
    if(result2[1][j] > maxV){
      maxV = result2[1][j];
      maxI = result2[0][j];
      c=j;
    }
  }
    //cout << "result[" << i << "] = " << result[i] << endl;
  cout << maxI <<" "<<maxV << endl;
  maxV = -1;
  result2[1][c]=-1;
  c=0;
  }
}
