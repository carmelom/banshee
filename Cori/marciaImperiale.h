int pitchMarciaImperiale[67], 
durationMarciaImperiale[67]={1,500,500,500,375,125,500,375,125,1000,500,500,500,375,125,500,375,125,1000,500,375,125,500,375,125,125,125,500,250,500,375,125,125,125,500,250,500,375,125,500,375,125,1000,500,375,125,500,375,125,125,125,500,250,500,375,125,125,125,500,250,500,375,125,500,375,125,1000};
double scaleMarciaImperiale = 1.0;
double transportMarciaImperiale = 1.0;

void initMarciaImperiale() {
pitchMarciaImperiale[0]=440;
pitchMarciaImperiale[1]=NOTE_G4;
pitchMarciaImperiale[2]=NOTE_G4;
pitchMarciaImperiale[3]=NOTE_G4;
pitchMarciaImperiale[4]=NOTE_DS4;
pitchMarciaImperiale[5]=NOTE_AS4;
pitchMarciaImperiale[6]=NOTE_G4;
pitchMarciaImperiale[7]=NOTE_DS4;
pitchMarciaImperiale[8]=NOTE_AS4;
pitchMarciaImperiale[9]=NOTE_G4;

pitchMarciaImperiale[10]=NOTE_D5;
pitchMarciaImperiale[11]=NOTE_D5;
pitchMarciaImperiale[12]=NOTE_D5;
pitchMarciaImperiale[13]=NOTE_DS5;
pitchMarciaImperiale[14]=NOTE_AS5;
pitchMarciaImperiale[15]=NOTE_FS4;
pitchMarciaImperiale[16]=NOTE_DS4;
pitchMarciaImperiale[17]=NOTE_AS4;
pitchMarciaImperiale[18]=NOTE_G4;

pitchMarciaImperiale[19]=NOTE_G5;
pitchMarciaImperiale[20]=NOTE_G4;
pitchMarciaImperiale[21]=NOTE_G4;
pitchMarciaImperiale[22]=NOTE_G5;
pitchMarciaImperiale[23]=NOTE_FS5;
pitchMarciaImperiale[24]=NOTE_F5;
pitchMarciaImperiale[25]=NOTE_E5;
pitchMarciaImperiale[26]=NOTE_DS5;
pitchMarciaImperiale[27]=NOTE_E5;
pitchMarciaImperiale[28]=NOTE_GS4;
pitchMarciaImperiale[29]=NOTE_CS5;
pitchMarciaImperiale[30]=NOTE_C5;
pitchMarciaImperiale[31]=NOTE_B4;
pitchMarciaImperiale[32]=NOTE_AS4;
pitchMarciaImperiale[33]=NOTE_A4;
pitchMarciaImperiale[34]=NOTE_AS4;
pitchMarciaImperiale[35]=NOTE_DS4;
pitchMarciaImperiale[36]=NOTE_FS4;
pitchMarciaImperiale[37]=NOTE_DS4;
pitchMarciaImperiale[38]=NOTE_G4;
pitchMarciaImperiale[39]=NOTE_B4;
pitchMarciaImperiale[40]=NOTE_G4;
pitchMarciaImperiale[41]=NOTE_B4;
pitchMarciaImperiale[42]=NOTE_D5;

pitchMarciaImperiale[43]=NOTE_G5;
pitchMarciaImperiale[44]=NOTE_G4;
pitchMarciaImperiale[45]=NOTE_G4;
pitchMarciaImperiale[46]=NOTE_G5;
pitchMarciaImperiale[47]=NOTE_FS5;
pitchMarciaImperiale[48]=NOTE_F5;
pitchMarciaImperiale[49]=NOTE_E5;
pitchMarciaImperiale[50]=NOTE_DS5;
pitchMarciaImperiale[51]=NOTE_E5;
pitchMarciaImperiale[52]=NOTE_GS4;
pitchMarciaImperiale[53]=NOTE_CS5;
pitchMarciaImperiale[54]=NOTE_C5;
pitchMarciaImperiale[55]=NOTE_B4;
pitchMarciaImperiale[56]=NOTE_AS4;
pitchMarciaImperiale[57]=NOTE_A4;
pitchMarciaImperiale[58]=NOTE_AS4;
pitchMarciaImperiale[59]=NOTE_DS4;
pitchMarciaImperiale[60]=NOTE_FS4;
pitchMarciaImperiale[61]=NOTE_DS4;
pitchMarciaImperiale[62]=NOTE_AS4;
pitchMarciaImperiale[63]=NOTE_G4;
pitchMarciaImperiale[64]=NOTE_DS4;
pitchMarciaImperiale[65]=NOTE_AS4;
pitchMarciaImperiale[66]=NOTE_G4;
}

void playMarciaImperiale() {
  currentDuration = durationMarciaImperiale;
  currentPitch = pitchMarciaImperiale;
  currentPos = 0;
  currentLen = sizeof(durationMarciaImperiale) / sizeof(durationMarciaImperiale[0]);
  currentScale = scaleMarciaImperiale;
  currentTransport = transportMarciaImperiale;
}
