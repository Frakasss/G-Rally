

void outputScreen_clear(){
  gb.display.clear();
}

//#################################
//##### FULLSCREEN GAMEMAKERS #####
//#################################
void outputScreen_gamemakers(){
  gb.display.setColor(BLACK);
  Image GameMakers(GamemakersData);
  gb.display.drawImage(0,0,GameMakers,160,128); 
}


//#################################
//##### FULLSCREEN TITRE ##########
//#################################
void outputScreen_title(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,80);
  Image Title(TitleData);
  Image Bkg_Tree(Bkg_TreeData);
  Image Bkg_Ground(Bkg_GroundData);
  Image Bkg_Car(Bkg_CarData);
  gb.display.drawImage(0,74,Bkg_Ground);
  gb.display.drawImage(0,0,Bkg_Tree);
  gb.display.drawImage(22,1,Title);
  gb.display.drawImage(7,39,Bkg_Car);
}

//###################################
//##### FULLSCREEN CREDITS ##########
//###################################
void outputScreen_credits(){
  Image Credits(Credits_Data);
  gb.display.drawImage(0,0,Credits,160,128);
}

//######################################
//############# MENU ###################
//######################################
void outputScreen_menu(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,128);

  outputScreen_background();
  
  Image Title(TitleData);
  gb.display.drawImage(22,1,Title);

  if(game.menuOption == 1){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(130, 52);
  gb.display.println("Race!");

  if(game.menuOption == 2){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(110, 62);
  gb.display.println("Select Car");

  if(game.menuOption == 3){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(110, 72);
  gb.display.println("Select Map");

  if(game.menuOption == 4){gb.display.setColor(WHITE);}else{gb.display.setColor(BLACK);}
  gb.display.setCursor(122, 82);
  gb.display.println("Credits");

  if(game.menuOption == 1){
    Image Flag(FlagData);
    Image Game_CarSelection(Game_CarSelectionData);
    outputScreen_map();
    gb.display.setColor(BLACK);
    gb.display.drawRect(9,50,42,35);
    gb.display.drawImage(55,55,Flag,0,(game.globalTimer%3)*26,27,26);
    gb.display.drawImage(30,75,Game_CarSelection,0,car01.type*27,40,27);
  }
  if(game.menuOption == 2){
    Image Game_CarSelection(Game_CarSelectionData);
    gb.display.drawImage(12,50,Game_CarSelection,0,2*27,40,27);
    gb.display.drawImage(50,50,Game_CarSelection,0,1*27,40,27);
    gb.display.drawImage(30,70,Game_CarSelection,0,0*27,40,27);
    gb.display.setColor(BLACK);
    gb.display.drawLine(0,45,50,45);
    gb.display.drawLine(0,99,70,99);
  }
  if(game.menuOption == 3){
    Image WorldMap(WorldMapData);
    gb.display.drawImage(-10,45,WorldMap);
    gb.display.setColor(BLACK);
    gb.display.drawLine(0,45,50,45);
    gb.display.drawLine(0,99,70,99);
  }
  if(game.menuOption == 4){
    Image CreditsIco(CreditsIcoData);
    gb.display.drawImage(32,60,CreditsIco);
    gb.display.setColor(BLACK);
    gb.display.drawLine(0,45,50,45);
    gb.display.drawLine(0,99,70,99);
  }
}


//###########################
//##### Game ################
//###########################
void outputScreen_map(){
  if(mapSelected==0){
    if(game.gameStatus==MAPSELECTION) {Image Map000(Map000Data);  gb.display.drawImage(40,60,Map000,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map000(Map000Data);  gb.display.drawImage(10,50,Map000,40,34);}
    else                              {Image Map000(Map000Data);  gb.display.drawImage(0,-2,Map000,160,130);} 
  } 
  if(mapSelected==1){
    if(game.gameStatus==MAPSELECTION) {Image Map001(Map001Data);  gb.display.drawImage(40,60,Map001,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map001(Map001Data);  gb.display.drawImage(10,50,Map001,40,34);}
    else                              {Image Map001(Map001Data);  gb.display.drawImage(0,-2,Map001,160,130);} 
  }   
  if(mapSelected==2){
    if(game.gameStatus==MAPSELECTION) {Image Map002(Map002Data);  gb.display.drawImage(40,60,Map002,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map002(Map002Data);  gb.display.drawImage(10,50,Map002,40,34);}
    else                              {Image Map002(Map002Data);  gb.display.drawImage(0,-2,Map002,160,130);} 
  }
  if(mapSelected==3){
    if(game.gameStatus==MAPSELECTION) {Image Map003(Map003Data);  gb.display.drawImage(40,60,Map003,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map003(Map003Data);  gb.display.drawImage(10,50,Map003,40,34);}
    else                              {Image Map003(Map003Data);  gb.display.drawImage(0,-2,Map003,160,130);} 
  }
  if(mapSelected==4){
    if(game.gameStatus==MAPSELECTION) {Image Map004(Map004Data);  gb.display.drawImage(40,60,Map004,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map004(Map004Data);  gb.display.drawImage(10,50,Map004,40,34);}
    else                              {Image Map004(Map004Data);  gb.display.drawImage(0,-2,Map004,160,130);} 
  }
  if(mapSelected==5){
    if(game.gameStatus==MAPSELECTION) {Image Map005(Map005Data);  gb.display.drawImage(40,60,Map005,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map005(Map005Data);  gb.display.drawImage(10,50,Map005,40,34);}
    else                              {Image Map005(Map005Data);  gb.display.drawImage(0,-2,Map005,160,130);} 
  }
  if(mapSelected==6){
    if(game.gameStatus==MAPSELECTION) {Image Map006(Map006Data);  gb.display.drawImage(40,60,Map006,0,1,80,64);}
    else if(game.gameStatus==MENU)    {Image Map006(Map006Data);  gb.display.drawImage(10,50,Map006,40,34);}
    else                              {Image Map006(Map006Data);  gb.display.drawImage(0,-2,Map006,160,130);} 
  }
}

void outputScreen_background(){
  Image Background001(Background001Data);
  Image Background002(Background002Data);
  gb.display.drawImage(0,20,Background001);
  gb.display.drawImage(61,97,Background002);
  gb.display.drawImage(61,0,Background002,-97,-31);
  
  //gb.display.drawImage(99,0,Background001,-61,-108);
  //gb.display.drawImage(2,0,Background002,-97,-31);
  
  
}

void outputScreen_trajectory(){
  gb.display.setColor(GRAY);
  for(int i = 1;i<100;i++){
    if(replay[i].x!=0 and replay[i].y!=0){
      gb.display.drawLine(replay[i-1].x,replay[i-1].y,replay[i].x,replay[i].y);
    }
  }
}

void outputScreen_grid(){
  if(displayGrid==true){ 
    int jj=maps[0].y%car01.squareSize;
    int ii=maps[0].x%car01.squareSize;
    gb.display.setColor(RED);
    for(int j=jj;j<128;j=j+car01.squareSize){
      for(int i=ii;i<160;i=i+car01.squareSize){
        gb.display.drawPixel(i,j);
      }
    }
    displayGrid=false;
  }
}

void outputScreen_car(){
  Image Game_Car = Image(Game_CarData);
  gb.display.drawImage(car01.x-5,car01.y-5,Game_Car,11*car01.pos,11*car01.type,11,11);
}

void outputScreen_carReplay(){
  Image Game_Car = Image(Game_CarData);
  int16_t pos = replay[replayCounter].pos;
  if(pos==99){pos = replay[replayCounter-1].pos;}
  gb.display.drawImage(replay[replayCounter].x-5,replay[replayCounter].y-5,Game_Car,11*pos,11*car01.type,11,11);
}

void outputScreen_cursor(){
  gb.display.setColor(WHITE);
  int16_t xx = car01.x+car01.previousX+cur.x;
  int16_t yy = car01.y+car01.previousY+cur.y;
  gb.display.drawPixel(xx-1,yy);
  gb.display.drawPixel(xx,yy-1);
  gb.display.drawPixel(xx+1,yy);
  gb.display.drawPixel(xx,yy+1);
}


//###########################
//### PAUSE / GAME OVER #####
//###########################
void outputScreen_gameOver(){
  gb.display.setColor(BLACK);
  gb.display.fillRect(43,38,74,44);
  
  gb.display.setColor(RED);
  gb.display.setFontSize(2);
  gb.display.setCursor(45,41);
  gb.display.println("GAME OVER");

  gb.display.setFontSize(1);
  
  if(game.menuPauseOption==0){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(62,60);
  gb.display.println("Try Again");
  
  if(game.menuPauseOption==1){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(56,70);
  gb.display.println("Back to Menu");
}

void outputScreen_winner(){
  gb.display.setColor(BLACK);
  gb.display.fillRect(43,38,74,64);
  
  gb.display.setColor(YELLOW);
  gb.display.setFontSize(2);
  gb.display.setCursor(45,41);
  gb.display.println("FINISHED!");

  gb.display.setColor(WHITE);
  gb.display.setFontSize(1);
  gb.display.setCursor(50,54);
  gb.display.println("Your score:");
  gb.display.setCursor(98,54);
  gb.display.println(replayCounter);

  if(game.menuPauseOption==0){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(68,70);
  gb.display.println("Replay");
  
  if(game.menuPauseOption==1){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(62,80);
  gb.display.println("Next Race");
  
  if(game.menuPauseOption==2){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(56,90);
  gb.display.println("Back to Menu");
  
}

void outputScreen_menuPause(){
  gb.display.setColor(BLACK);
  gb.display.fillRect(48,38,64,54);
  
  gb.display.setColor(LIGHTGREEN);
  gb.display.setFontSize(2);
  gb.display.setCursor(61,41);
  gb.display.println("PAUSE");

  gb.display.setFontSize(1);
  
  if(game.menuPauseOption==0){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(64,60);
  gb.display.println("Continue");
  
  if(game.menuPauseOption==1){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(70,70);
  gb.display.println("Reset");

  if(game.menuPauseOption==2){gb.display.setColor(LIGHTBLUE);}else{gb.display.setColor(WHITE);}
  gb.display.setCursor(56,80);
  gb.display.println("Back to Menu");
}

//###########################
//##### CAR SELECTION #######
//###########################
void outputScreen_carSelection(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,128);
  
  outputScreen_background();
  
  Image Title(TitleData);
  gb.display.drawImage(22,1,Title);
  
  gb.display.setColor(WHITE);
  gb.display.setCursor(105,35);
  gb.display.println("Car Selection");

  Image Game_CarSelection(Game_CarSelectionData);
  gb.display.drawImage(60,60,Game_CarSelection,0,car01.type*27,40,27);

  gb.display.setColor(BLACK);
  gb.display.fillRect(25,90,110,30);

  gb.display.setColor(WHITE);
  gb.display.setCursor(30,97);
  gb.display.println("Acceleration: ");  
  gb.display.setCursor(30,107);
  gb.display.println("Break: "); 
}


//###########################
//##### MAP SELECTION #######
//###########################
void outputScreen_mapSelection(){
  gb.display.setColor(LIGHTBLUE);
  gb.display.fillRect(0,0,160,128);

  outputScreen_background();
  
  Image Title(TitleData);
  gb.display.drawImage(22,1,Title);
  
  gb.display.setColor(WHITE);
  gb.display.setCursor(105,35);
  gb.display.println("Map Selection");

  gb.display.setCursor(40,52);
  gb.display.println(maps[mapSelected].title);  
  
  outputScreen_map();

  gb.display.setColor(BLACK);
  gb.display.drawRect(39,59,82,66);
}
