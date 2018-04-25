
/**
 * @file Phase1.1.cc
 * @brief フェーズ１−１のコードです
 * @author YukiFunayama
 * @date 4/18
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
  //cout << "data1 = " << data1 << endl;
  double data2 = pow(BR3-BR4,2);
  //cout << "data2 = " << data2 << endl;
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
  double data[n1][n2];
  for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
      cin >> data[i][j];
    }
  }
  for(int i=1;i<n1;i++){
    double score=0;
    count = 0;

    for(int j=0;j<n2;j++){
      for(int k=1+j;k<n2;k++){
      if(data[0][j]==-1||data[i][j]==-1||data[0][k]==-1||data[i][k]==-1) continue;
      score = score + EuclideanDistance(data[0][j],data[i][j],data[0][k],data[i][k]);
      //cout << "score = " << score << endl;
      count++;
      //cout << "data[0][" << j << "] = " << data[0][j] << ",data[" << i <<"]["<< j << "] = " << data[i][j] << ",data[0][" << k << "] = " << data[0][k] << ",data[" << i <<"]["<<k<<"] = "<< data[i][k] << endl;
      }
    }
    //cout << "coutn = " << count <<endl;
    //cout << "score/count = " << score/count <<endl;
    result[i+1]=score/count;
  }
  double maxV = result[2];
  int maxI = 0;
  for(int j=2;j<n2;j++){
    for(int i=2;i<n2;i++){
      if(result[i] > maxV){
        maxV = result[i];
        maxI = i;
      }
      //cout << "result[" << i << "] = " << result[i] << endl;
    }
    cout << maxI <<" "<<maxV << endl;
    maxV = -1;
    result[maxI]=-1;
  }
  return 0;
}
