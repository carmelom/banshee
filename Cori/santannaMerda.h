int durationSantannaMerda[46], pitchSantannaMerda[46];
double scaleSantannaMerda = 1.0;
double transportSantannaMerda = 1.0;

void initSantannaMerda() {
durationSantannaMerda[0]=1;
durationSantannaMerda[1]=250;
durationSantannaMerda[2]=250;
durationSantannaMerda[3]=250;
durationSantannaMerda[4]=500;
durationSantannaMerda[5]=500;
durationSantannaMerda[6]=250;
durationSantannaMerda[7]=250;
durationSantannaMerda[8]=250;
durationSantannaMerda[9]=250;
durationSantannaMerda[10]=500;
durationSantannaMerda[11]=750;

durationSantannaMerda[12]=250;
durationSantannaMerda[13]=250;
durationSantannaMerda[14]=250;
durationSantannaMerda[15]=500;
durationSantannaMerda[16]=500;
durationSantannaMerda[17]=250;
durationSantannaMerda[18]=250;
durationSantannaMerda[19]=250;
durationSantannaMerda[20]=250;
durationSantannaMerda[21]=500;
durationSantannaMerda[22]=750;

durationSantannaMerda[23]=250;
durationSantannaMerda[24]=250;
durationSantannaMerda[25]=250;
durationSantannaMerda[26]=500;
durationSantannaMerda[27]=750;
durationSantannaMerda[28]=250;
durationSantannaMerda[29]=250;
durationSantannaMerda[30]=250;
durationSantannaMerda[31]=500;
durationSantannaMerda[32]=750;

durationSantannaMerda[33]=250;
durationSantannaMerda[34]=250;
durationSantannaMerda[35]=250;
durationSantannaMerda[36]=250;
durationSantannaMerda[37]=250;
durationSantannaMerda[38]=250;
durationSantannaMerda[39]=250;
durationSantannaMerda[40]=250;
durationSantannaMerda[41]=250;
durationSantannaMerda[42]=250;
durationSantannaMerda[43]=250;
durationSantannaMerda[44]=500;
durationSantannaMerda[45]=500;

pitchSantannaMerda[0]=440;
pitchSantannaMerda[1]=NOTE_G4;
pitchSantannaMerda[2]=NOTE_G4;
pitchSantannaMerda[3]=NOTE_G4;
pitchSantannaMerda[4]=NOTE_E4;
pitchSantannaMerda[5]=NOTE_E4;
pitchSantannaMerda[6]=NOTE_G4;
pitchSantannaMerda[7]=NOTE_G4;
pitchSantannaMerda[8]=NOTE_G4;
pitchSantannaMerda[9]=NOTE_G4;
pitchSantannaMerda[10]=NOTE_E4;
pitchSantannaMerda[11]=NOTE_E4;

pitchSantannaMerda[12]=NOTE_G4;
pitchSantannaMerda[13]=NOTE_G4;
pitchSantannaMerda[14]=NOTE_G4;
pitchSantannaMerda[15]=NOTE_E4;
pitchSantannaMerda[16]=NOTE_E4;
pitchSantannaMerda[17]=NOTE_E4;
pitchSantannaMerda[18]=NOTE_E4;
pitchSantannaMerda[19]=NOTE_D4;
pitchSantannaMerda[20]=NOTE_E4;
pitchSantannaMerda[21]=NOTE_F4;
pitchSantannaMerda[22]=NOTE_F4;

pitchSantannaMerda[23]=NOTE_F4;
pitchSantannaMerda[24]=NOTE_F4;
pitchSantannaMerda[25]=NOTE_F4;
pitchSantannaMerda[26]=NOTE_F4;
pitchSantannaMerda[27]=NOTE_F4;
pitchSantannaMerda[28]=NOTE_F4;
pitchSantannaMerda[29]=NOTE_F4;
pitchSantannaMerda[30]=NOTE_F4;
pitchSantannaMerda[31]=NOTE_F4;
pitchSantannaMerda[32]=NOTE_F4;

pitchSantannaMerda[33]=NOTE_F4;
pitchSantannaMerda[34]=NOTE_F4;
pitchSantannaMerda[35]=NOTE_F4;
pitchSantannaMerda[36]=NOTE_F4;
pitchSantannaMerda[37]=NOTE_F4;
pitchSantannaMerda[38]=NOTE_F4;
pitchSantannaMerda[39]=NOTE_F4;
pitchSantannaMerda[40]=NOTE_G4;
pitchSantannaMerda[41]=NOTE_G4;
pitchSantannaMerda[42]=NOTE_G4;
pitchSantannaMerda[43]=NOTE_G4;
pitchSantannaMerda[44]=NOTE_E4;
pitchSantannaMerda[45]=NOTE_E4;
}

void playSantannaMerda() {
  currentDuration = durationSantannaMerda;
  currentPitch = pitchSantannaMerda;
  currentPos = 0;
  currentLen = sizeof(durationSantannaMerda) / sizeof(durationSantannaMerda[0]);
  currentScale = scaleSantannaMerda;
  currentTransport = transportSantannaMerda;
  casinoMode = false;
}
