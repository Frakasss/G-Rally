void game_init(){
  game.gameStatus = GAMEMAKERS;
  game.globalTimer = 0;
  game.pause=0;
  game.menuOption=1;
  game.menuPauseOption=0;
}

void game_carInit(){
  car01.type=0;
  car01.squareSize=5;
}


//###################################################
//###################################################
//###################################################
void game_manageGlobalCounter(){
  switch ( game.gameStatus ){
     //#################################### 
     case GAMEMAKERS:
       
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        
        break;

     //####################################  
     case TITLESCREEN:
     
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = MENU;
        }
        break;
     //####################################  
     case MENU:
        game.globalTimer = game.globalTimer +1;
        if(game.globalTimer>29){game.globalTimer=0;}
        break;
        
     //####################################  
     case CREDITS:
        break;

     //####################################  
     case MAPSELECTION:
        break;

     //####################################  
     case CARSELECTION:
        break;
        
     //####################################  
     case GAME:

        break;
        
     //####################################  
     case GAMEOVER:
        break;     
        
     //####################################  
     case WINNER:
        break;  

     //####################################  
     case REPLAY:
        game.globalTimer = game.globalTimer +1;
        if(game.globalTimer>5){game.globalTimer=0;}
        break; 
             
     //####################################  
     case MENUPAUSE:
        break;

                          
     default:
        game.gameStatus = GAMEMAKERS;
        break;
  }
}




//###################################################
//###################################################
//###################################################
void game_initMapInfos(){
  maps[0].x=12;   maps[0].y=112;  maps[0].pos=4;  maps[0].bestScore=10; maps[0].title="The Training";
  maps[1].x=74;   maps[1].y=10;   maps[1].pos=4;  maps[1].bestScore=10; maps[1].title="Cut the Curve";
  maps[2].x=10;   maps[2].y=120;  maps[2].pos=0;  maps[2].bestScore=10; maps[2].title="Turn around";
  maps[3].x=156;  maps[3].y=10;   maps[3].pos=10; maps[3].bestScore=10; maps[3].title="The River";
  maps[4].x=80;   maps[4].y=10;   maps[4].pos=4;  maps[4].bestScore=10; maps[4].title="Shortcut";
  maps[5].x=74;   maps[5].y=10;   maps[5].pos=4;  maps[5].bestScore=10; maps[5].title="Paris Dakar";
  maps[6].x=-20;    maps[6].y=64;   maps[6].pos=4;  maps[6].bestScore=10; maps[6].title="Driving License";

}


void game_initCarPosition(){
  car01.previousX=0;
  car01.previousY=0;
  car01.x=maps[mapSelected].x; 
  car01.y=maps[mapSelected].y; 
  car01.pos=maps[mapSelected].pos;
}

void game_initActiveColors(){
  if(mapSelected==0){  Image Map000(Map000Data);  gb.display.drawImage(0,0,Map000,0,0,10,1);} 
  if(mapSelected==1){  Image Map001(Map001Data);  gb.display.drawImage(0,0,Map001,0,0,10,1);} 
  if(mapSelected==2){  Image Map002(Map002Data);  gb.display.drawImage(0,0,Map002,0,0,10,1);} 
  if(mapSelected==3){  Image Map003(Map003Data);  gb.display.drawImage(0,0,Map003,0,0,10,1);} 
  if(mapSelected==4){  Image Map004(Map004Data);  gb.display.drawImage(0,0,Map004,0,0,10,1);} 
  if(mapSelected==5){  Image Map005(Map005Data);  gb.display.drawImage(0,0,Map005,0,0,10,1);}
  if(mapSelected==6){  Image Map006(Map006Data);  gb.display.drawImage(0,0,Map006,0,0,10,1);}
  road = gb.display.getPixelColor(0,0);
  speedKiller1 = gb.display.getPixelColor(1,0);
  speedKiller2 = gb.display.getPixelColor(2,0);
  handlingKiller1 = gb.display.getPixelColor(3,0);
  handlingKiller2 = gb.display.getPixelColor(4,0);
  instantDeath1 = gb.display.getPixelColor(5,0);
  instantDeath2 = gb.display.getPixelColor(6,0);
  checkpoint = gb.display.getPixelColor(7,0);
  finish = gb.display.getPixelColor(8,0); 
}

void game_resetReplay(){
  for(int i = 0; i<300; i++){
    replay[i].x=0;
    replay[i].y=0;
    replay[i].pos=99;
  }
  replayCounter=0;
  replay[0].x=car01.x;
  replay[0].y=car01.y;
}

void game_resetCursor(){
  cur.x=0;
  cur.y=0;
  cur.isActive=true;
}

void game_setCarPosition(){
  int16_t xxx = car01.previousX+cur.x;
  int16_t yyy = car01.previousY+cur.y;
  
  if(xxx==0 and yyy<0){car01.pos=0;}
  if(xxx>0 and yyy<0 and abs(xxx)<abs(yyy)){car01.pos=1;}
  if(xxx>0 and yyy<0 and abs(xxx)==abs(yyy)){car01.pos=2;}
  if(xxx>0 and yyy<0 and abs(xxx)>abs(yyy)){car01.pos=3;}
  if(xxx>0 and yyy==0){car01.pos=4;}
  if(xxx>0 and yyy>0 and abs(xxx)>abs(yyy)){car01.pos=5;}
  if(xxx>0 and yyy>0 and abs(xxx)==abs(yyy)){car01.pos=6;}
  if(xxx>0 and yyy>0 and abs(xxx)<abs(yyy)){car01.pos=7;}
  if(xxx==0 and yyy>0){car01.pos=8;}
  if(xxx<0 and yyy>0 and abs(xxx)<abs(yyy)){car01.pos=9;}
  if(xxx<0 and yyy>0 and abs(xxx)==abs(yyy)){car01.pos=10;}
  if(xxx<0 and yyy>0 and abs(xxx)>abs(yyy)){car01.pos=11;}
  if(xxx<0 and yyy==0){car01.pos=12;}
  if(xxx<0 and yyy<0 and abs(xxx)>abs(yyy)){car01.pos=13;}
  if(xxx<0 and yyy<0 and abs(xxx)==abs(yyy)){car01.pos=14;}
  if(xxx<0 and yyy<0 and abs(xxx)<abs(yyy)){car01.pos=15;}
}

void game_recordReplay(){
  replayCounter++;
  replay[replayCounter].x=car01.x;
  replay[replayCounter].y=car01.y;
  replay[replayCounter-1].pos=car01.pos;
}

void game_replayFrameManager(){
  if(game.globalTimer==0){
    replayCounter=replayCounter+1;
    if(replay[replayCounter].x==0 and replay[replayCounter].y==0 and replay[replayCounter].pos==99){game.gameStatus = WINNER;}
  }
}

//###################################################
//###################################################
//###################################################
/*
Color road;
Color speedKiller1;
Color speedKiller2;
Color handlingKiller1;
Color handlingKiller2;
Color instantDeath1;
Color instantDeath2;
Color checkpoint;
Color finish;
 */

void game_checkSpeedKiller(){
  if(gb.display.getPixelColor(car01.x,car01.y)==speedKiller1){
    car01.previousX=0;
    car01.previousY=0;
  }
  if(gb.display.getPixelColor(car01.x,car01.y)==speedKiller2){
    car01.previousX=0;
    car01.previousY=0;
  }
}

void game_checkHandlingKiller(){
  if(gb.display.getPixelColor(car01.x,car01.y)==handlingKiller1){
    cur.isActive=false;
  }
  if(gb.display.getPixelColor(car01.x,car01.y)==handlingKiller2){
    cur.isActive=false;
  }
}

void game_checkOutOfScreen(){
  if(car01.x<0){game.gameStatus = GAMEOVER;}
  if(car01.x>160){game.gameStatus = GAMEOVER;}
  if(car01.y<0){game.gameStatus = GAMEOVER;}
  if(car01.y>128){game.gameStatus = GAMEOVER;}
}

void game_checkInstantDeath(){
  for(int16_t i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,instantDeath1)){game.gameStatus = GAMEOVER;}
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,instantDeath2)){game.gameStatus = GAMEOVER;}
    }
  }
}

void game_checkCheckpoint(){
  for(int16_t i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,checkpoint)){/*Count number of checkpoints (??)*/}
    }
  }  
}

void game_checkFinish(){
  for(int16_t i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      if(collideLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y,finish)){game.gameStatus = WINNER;}
    }
  }   
}



//###################################################
//###################################################
//###################################################
bool collideLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, Color toBeChecked) {
  bool isCollision=false;
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    _swap_int16_t(x0, y0);
    _swap_int16_t(x1, y1);
  }

  if (x0 > x1) {
    _swap_int16_t(x0, x1);
    _swap_int16_t(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0<=x1; x0++) {
    if (steep) {
      if(y0>0 and y0<160 and x0>0 and x0<128){
        if(gb.display.getPixelColor(y0, x0)==toBeChecked){isCollision=true;}
      }
    } else {
      if(x0>0 and x0<160 and y0>0 and y0<128){
        if(gb.display.getPixelColor(x0, y0)==toBeChecked){isCollision=true;}
      }
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
  return isCollision;
}

bool checkCollide(int16_t x1, int16_t y1, int16_t w1, int16_t h1, int16_t x2, int16_t y2, int16_t w2, int16_t h2){
  return (x2<x1+w1 && x2+w2>x1 && y2<y1+h1 && y2+h2>y1);
}
