#include <iostream>
using namespace std;

class Bourd {
private:
   char bord[3][3] = {};
public:
   Bourd(){
      for (int i = 0; i < 3; i++) {
         for(int j = 0; j < 3; j++)  {
            bord[i][j] = '-';
         }
      }
   }
   void showBourd() {
      for (int i = 0; i < 3; i++) {
         cout << "-------------\n|";
         for(int j = 0; j < 3; j++)  {
            cout << " " << bord[i][j] << " |";
         }
         cout << "\n";
      }
      cout << "-------------\n";
      
   }

   void setBourdChar(char c) {
      int x,y;
      while (true) {
      cout << "Enter the x-positon (1 - 3) : ";
      cin >> x;
      cout << "Enter the y-positon (1 - 3) : ";
      cin >> y;
      if(bord[x-1][y-1] == '-') break;
      else cout << "position taken, chocice other postion\n";
      }
      bord[x-1][y-1] = c;
   }
   char getbourdChar(int x, int y) {
      return bord[x-1][y-1];
   }
};

class Player {
private:
   char c;
public:
   Player(char a):c(a) {
   }
   char getXorO() {
      return c;
   }
   bool checkWin(Bourd *b) {
      
      if((b->getbourdChar(1,1) == b->getbourdChar(1,2)) && 
       (b->getbourdChar(1,2) == b->getbourdChar(1,3)) && (b->getbourdChar(1,3) !='-')) 
         return true;
      
      else if((b->getbourdChar(2,1) == b->getbourdChar(2,2)) && 
       (b->getbourdChar(2,2) == b->getbourdChar(2,3)) && (b->getbourdChar(2,3) != '-')) 
         return true;
      
      else if((b->getbourdChar(3,1) == b->getbourdChar(3,2)) &&
       (b->getbourdChar(3,2) == b->getbourdChar(3,3)) && (b->getbourdChar(3,3) != '-')) 
         return true;   
      
      else if((b->getbourdChar(1,1) == b->getbourdChar(2,1)) &&
       (b->getbourdChar(2,1) == b->getbourdChar(3,1)) && (b->getbourdChar(3,1) != '-')) 
         return true;
      
      else if((b->getbourdChar(1,2) == b->getbourdChar(2,2)) &&
       (b->getbourdChar(2,2) == b->getbourdChar(3,2)) && (b->getbourdChar(3,2) != '-')) 
         return true;
      
      else if(b->getbourdChar(1,3) == b->getbourdChar(2,3) && 
       (b->getbourdChar(2,3) == b->getbourdChar(3,3)) && (b->getbourdChar(3,3) != '-')) 
         return true;
      
      else if((b->getbourdChar(1,1) == b->getbourdChar(2,2)) &&
       (b->getbourdChar(2,2) == b->getbourdChar(3,3)) && (b->getbourdChar(3,3) != '-')) 
         return true;
      else if((b->getbourdChar(1,3) == b->getbourdChar(2,2)) &&
       (b->getbourdChar(2,2) == b->getbourdChar(3,1)) && (b->getbourdChar(3,1) != '-')) 
         return true;
      else 
         return false;
      }
};

int main() {

   Bourd bord;
   Player player1('X');
   Player player2('O');
   while(true){
      bord.showBourd();
      cout << "Player 1 \n";
      bord.setBourdChar(player1.getXorO());
      if(player1.checkWin(&bord)){cout << "PLAYER 1 WIN\n"; bord.showBourd(); break;}
      bord.showBourd();
      cout << "Player 2 \n";
      bord.setBourdChar(player2.getXorO());
      if(player2.checkWin(&bord)){cout << "PLAYER 1 WIN\n"; bord.showBourd(); break;}
      bord.showBourd();
   }
}