int pitchLaTrionfera[82], 
durationLaTrionfera[82]={1,125,375,125,500,875,125,375,125,500,875,125,375,125,500,875,125,375,125,500,875,125,375,125,500,875,125,375,125,500,875,125,375,125,500,875,125,375,125,1000,500,375,125,250,250,250,250,500,500,1000,500,375,125,250,250,250,250,500,500,1000,500,375,125,250,250,250,250,500,500,1000,500,375,125,250,250,250,250,500,500,500};
double scaleLaTrionfera = 1.0;
double transportLaTrionfera = 1.0;

void initLaTrionfera() {
pitchLaTrionfera[0]=440;
pitchLaTrionfera[1]=NOTE_F4;
pitchLaTrionfera[2]=NOTE_F4;
pitchLaTrionfera[3]=NOTE_G4;
pitchLaTrionfera[4]=NOTE_A4;
pitchLaTrionfera[5]=NOTE_A4;
pitchLaTrionfera[6]=NOTE_G4;
pitchLaTrionfera[7]=NOTE_F4;
pitchLaTrionfera[8]=NOTE_G4;
pitchLaTrionfera[9]=NOTE_A4;
pitchLaTrionfera[10]=NOTE_A4;

pitchLaTrionfera[11]=NOTE_A4;
pitchLaTrionfera[12]=NOTE_AS4;
pitchLaTrionfera[13]=NOTE_A4;
pitchLaTrionfera[14]=NOTE_A4;
pitchLaTrionfera[15]=NOTE_G4;
pitchLaTrionfera[16]=NOTE_G4;
pitchLaTrionfera[17]=NOTE_A4;
pitchLaTrionfera[18]=NOTE_G4;
pitchLaTrionfera[19]=NOTE_G4;
pitchLaTrionfera[20]=NOTE_F4;

pitchLaTrionfera[21]=NOTE_F4;
pitchLaTrionfera[22]=NOTE_F4;
pitchLaTrionfera[23]=NOTE_G4;
pitchLaTrionfera[24]=NOTE_A4;
pitchLaTrionfera[25]=NOTE_A4;
pitchLaTrionfera[26]=NOTE_G4;
pitchLaTrionfera[27]=NOTE_F4;
pitchLaTrionfera[28]=NOTE_G4;
pitchLaTrionfera[29]=NOTE_A4;
pitchLaTrionfera[30]=NOTE_A4;

pitchLaTrionfera[31]=NOTE_A4;
pitchLaTrionfera[32]=NOTE_AS4;
pitchLaTrionfera[33]=NOTE_A4;
pitchLaTrionfera[34]=NOTE_A4;
pitchLaTrionfera[35]=NOTE_G4;
pitchLaTrionfera[36]=NOTE_AS4;
pitchLaTrionfera[37]=NOTE_A4;
pitchLaTrionfera[38]=NOTE_G4;
pitchLaTrionfera[39]=NOTE_F4;

pitchLaTrionfera[40]=NOTE_C5;
pitchLaTrionfera[41]=NOTE_C5;
pitchLaTrionfera[42]=NOTE_C5;
pitchLaTrionfera[43]=NOTE_C5;
pitchLaTrionfera[44]=NOTE_A4;
pitchLaTrionfera[45]=NOTE_AS4;
pitchLaTrionfera[46]=NOTE_C5;
pitchLaTrionfera[47]=NOTE_D5;
pitchLaTrionfera[48]=NOTE_C5;
pitchLaTrionfera[49]=NOTE_AS4;

pitchLaTrionfera[50]=NOTE_AS4;
pitchLaTrionfera[51]=NOTE_AS4;
pitchLaTrionfera[52]=NOTE_AS4;
pitchLaTrionfera[53]=NOTE_AS4;
pitchLaTrionfera[54]=NOTE_G4;
pitchLaTrionfera[55]=NOTE_A4;
pitchLaTrionfera[56]=NOTE_AS4;
pitchLaTrionfera[57]=NOTE_C5;
pitchLaTrionfera[58]=NOTE_AS4;
pitchLaTrionfera[59]=NOTE_A4;

pitchLaTrionfera[60]=NOTE_C5;
pitchLaTrionfera[61]=NOTE_C5;
pitchLaTrionfera[62]=NOTE_C5;
pitchLaTrionfera[63]=NOTE_C5;
pitchLaTrionfera[64]=NOTE_A4;
pitchLaTrionfera[65]=NOTE_AS4;
pitchLaTrionfera[66]=NOTE_C5;
pitchLaTrionfera[67]=NOTE_D5;
pitchLaTrionfera[68]=NOTE_C5;
pitchLaTrionfera[69]=NOTE_AS4;

pitchLaTrionfera[70]=NOTE_AS4;
pitchLaTrionfera[71]=NOTE_AS4;
pitchLaTrionfera[72]=NOTE_AS4;
pitchLaTrionfera[73]=NOTE_AS4;
pitchLaTrionfera[74]=NOTE_AS4;
pitchLaTrionfera[75]=NOTE_A4;
pitchLaTrionfera[76]=NOTE_C5;
pitchLaTrionfera[77]=NOTE_C5;
pitchLaTrionfera[78]=NOTE_AS4;
pitchLaTrionfera[79]=NOTE_A4;
pitchLaTrionfera[80]=NOTE_G4;
pitchLaTrionfera[81]=NOTE_F4;
}

void playLaTrionfera() {
  currentDuration = durationLaTrionfera;
  currentPitch = pitchLaTrionfera;
  currentPos = 0;
  currentLen = sizeof(durationLaTrionfera) / sizeof(durationLaTrionfera[0]);
  currentScale = scaleLaTrionfera;
  currentTransport = transportLaTrionfera;
}
