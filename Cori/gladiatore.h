int pitchGladiatore[76], 
durationGladiatore[76]={500,500,500,750,250,1500,500,500,500,2500,500,500,500,750,250,1500,500,500,500,2000,1000,500,500,750,250,1500,500,500,500,1000,1000,1000,500,500,750,250,1000,500,500,500,500,750,250,1500,500,500,500,2500,500,500,500,750,250,1500,500,500,500,2000,1000,500,500,750,250,1500,500,500,500,1000,1000,1000,500,500,750,250,1000,2000};
double scaleGladiatore = 1.0;
double transportGladiatore = 1.0;

void initGladiatore() {
pitchGladiatore[0]=NOTE_A4;
pitchGladiatore[1]=NOTE_D4;
pitchGladiatore[2]=NOTE_E4;
pitchGladiatore[3]=NOTE_F4;
pitchGladiatore[4]=NOTE_E4;
pitchGladiatore[5]=NOTE_D4;

pitchGladiatore[6]=NOTE_D4;
pitchGladiatore[7]=NOTE_E4;
pitchGladiatore[8]=NOTE_F4;
pitchGladiatore[9]=NOTE_E4;

pitchGladiatore[10]=NOTE_A4;
pitchGladiatore[11]=NOTE_F4;
pitchGladiatore[12]=NOTE_G4;
pitchGladiatore[13]=NOTE_A4;
pitchGladiatore[14]=NOTE_G4;
pitchGladiatore[15]=NOTE_F4;

pitchGladiatore[16]=NOTE_F4;
pitchGladiatore[17]=NOTE_G4;
pitchGladiatore[18]=NOTE_A4;
pitchGladiatore[19]=NOTE_G4;

pitchGladiatore[20]=NOTE_G4;
pitchGladiatore[21]=NOTE_G4;
pitchGladiatore[22]=NOTE_A4;
pitchGladiatore[23]=NOTE_AS4;
pitchGladiatore[24]=NOTE_A4;
pitchGladiatore[25]=NOTE_G4;

pitchGladiatore[26]=NOTE_D4;
pitchGladiatore[27]=NOTE_D4;
pitchGladiatore[28]=NOTE_E4;
pitchGladiatore[29]=NOTE_F4;
pitchGladiatore[30]=NOTE_G4;
pitchGladiatore[31]=NOTE_A4;

pitchGladiatore[32]=NOTE_D4;
pitchGladiatore[33]=NOTE_E4;
pitchGladiatore[34]=NOTE_F4;
pitchGladiatore[35]=NOTE_E4;
pitchGladiatore[36]=NOTE_D4;
pitchGladiatore[37]=NOTE_C4;

pitchGladiatore[38]=NOTE_A3;
pitchGladiatore[39]=NOTE_D4;
pitchGladiatore[40]=NOTE_E4;
pitchGladiatore[41]=NOTE_F4;
pitchGladiatore[42]=NOTE_E4;
pitchGladiatore[43]=NOTE_D4;

pitchGladiatore[44]=NOTE_D4;
pitchGladiatore[45]=NOTE_E4;
pitchGladiatore[46]=NOTE_F4;
pitchGladiatore[47]=NOTE_E4;

pitchGladiatore[48]=NOTE_C4;
pitchGladiatore[49]=NOTE_F4;
pitchGladiatore[50]=NOTE_G4;
pitchGladiatore[51]=NOTE_A4;
pitchGladiatore[52]=NOTE_G4;
pitchGladiatore[53]=NOTE_F4;

pitchGladiatore[54]=NOTE_F4;
pitchGladiatore[55]=NOTE_G4;
pitchGladiatore[56]=NOTE_A4;
pitchGladiatore[57]=NOTE_G4;

pitchGladiatore[58]=NOTE_G4;
pitchGladiatore[59]=NOTE_G4;
pitchGladiatore[60]=NOTE_A4;
pitchGladiatore[61]=NOTE_AS4;
pitchGladiatore[62]=NOTE_A4;
pitchGladiatore[63]=NOTE_G4;

pitchGladiatore[64]=NOTE_D4;
pitchGladiatore[65]=NOTE_D4;
pitchGladiatore[66]=NOTE_E4;
pitchGladiatore[67]=NOTE_F4;
pitchGladiatore[68]=NOTE_G4;
pitchGladiatore[69]=NOTE_A4;
pitchGladiatore[70]=NOTE_D4;
pitchGladiatore[71]=NOTE_E4;
pitchGladiatore[72]=NOTE_F4;
pitchGladiatore[73]=NOTE_E4;
pitchGladiatore[74]=NOTE_D4;
pitchGladiatore[75]=NOTE_C4;
}

void playGladiatore() {
  currentDuration = durationGladiatore;
  currentPitch = pitchGladiatore;
  currentPos = 0;
  currentLen = sizeof(durationGladiatore) / sizeof(durationGladiatore[0]);
  currentScale = scaleGladiatore;
  currentTransport = transportGladiatore;
  casinoMode = false;
}

