int durationFiumeArno[34], pitchFiumeArno[34];
double scaleFiumeArno = 1.0;
double transportFiumeArno = 1.0;

void initFiumeArno() {
durationFiumeArno[0]=1;
durationFiumeArno[1]=250;
durationFiumeArno[2]=1000;
durationFiumeArno[3]=250;
durationFiumeArno[4]=250;
durationFiumeArno[5]=250;
durationFiumeArno[6]=500;
durationFiumeArno[7]=500;
durationFiumeArno[8]=1000;

durationFiumeArno[9]=250;
durationFiumeArno[10]=1000;
durationFiumeArno[11]=250;
durationFiumeArno[12]=250;
durationFiumeArno[13]=250;
durationFiumeArno[14]=500;
durationFiumeArno[15]=500;
durationFiumeArno[16]=1000;

durationFiumeArno[17]=250;
durationFiumeArno[18]=1000;
durationFiumeArno[19]=250;
durationFiumeArno[20]=250;
durationFiumeArno[21]=250;
durationFiumeArno[22]=250;
durationFiumeArno[23]=1000;

durationFiumeArno[24]=250;
durationFiumeArno[25]=250;
durationFiumeArno[26]=250;
durationFiumeArno[27]=250;
durationFiumeArno[28]=500;
durationFiumeArno[29]=250;
durationFiumeArno[30]=250;
durationFiumeArno[31]=500;
durationFiumeArno[32]=250;
durationFiumeArno[33]=1000;

pitchFiumeArno[0]=NOTE_A4;
pitchFiumeArno[1]=NOTE_D4;
pitchFiumeArno[2]=NOTE_B3;
pitchFiumeArno[3]=NOTE_B3;
pitchFiumeArno[4]=NOTE_C4;
pitchFiumeArno[5]=NOTE_D4;
pitchFiumeArno[6]=NOTE_B4;
pitchFiumeArno[7]=NOTE_B4;
pitchFiumeArno[8]=NOTE_G4;

pitchFiumeArno[9]=NOTE_D4;
pitchFiumeArno[10]=NOTE_B3;
pitchFiumeArno[11]=NOTE_B3;
pitchFiumeArno[12]=NOTE_C4;
pitchFiumeArno[13]=NOTE_B3;
pitchFiumeArno[14]=NOTE_D4;
pitchFiumeArno[15]=NOTE_D4;
pitchFiumeArno[16]=NOTE_C4;

pitchFiumeArno[17]=NOTE_C4;
pitchFiumeArno[18]=NOTE_A3;
pitchFiumeArno[19]=NOTE_A3;
pitchFiumeArno[20]=NOTE_B3;
pitchFiumeArno[21]=NOTE_C4;
pitchFiumeArno[22]=NOTE_D4;
pitchFiumeArno[23]=NOTE_B3;

pitchFiumeArno[24]=NOTE_B3;
pitchFiumeArno[25]=NOTE_CS4;
pitchFiumeArno[26]=NOTE_B3;
pitchFiumeArno[27]=NOTE_A3;
pitchFiumeArno[28]=NOTE_D4;
pitchFiumeArno[29]=NOTE_B3;
pitchFiumeArno[30]=NOTE_CS4;
pitchFiumeArno[31]=NOTE_A3;
pitchFiumeArno[32]=NOTE_CS4;
pitchFiumeArno[33]=NOTE_D4;
}

void playFiumeArno() {
  currentDuration = durationFiumeArno;
  currentPitch = pitchFiumeArno;
  currentPos = 0;
  currentLen = sizeof(durationFiumeArno) / sizeof(durationFiumeArno[0]);
  currentScale = scaleFiumeArno;
  currentTransport = transportFiumeArno;
  casinoMode = false;
}
