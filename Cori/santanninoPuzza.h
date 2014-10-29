int durationSantanninoPuzza[68]={250,375,125,250,250,250,500,250,375,125,250,250,750,250,375,125,250,250,375,125,250,250,250,250,250,250,750,250,375,125,250,250,250,500,250,375,125,250,250,750,250,375,125,250,250,375,125,250,250,250,250,250,250,750,250,375,125,250,250,375,125,250,250,250,250,250,250,500},
 pitchSantanninoPuzza[68];
double scaleSantanninoPuzza = 1.0;
double transportSantanninoPuzza = 1.0;

void initSantanninoPuzza() {
pitchSantanninoPuzza[0]=NOTE_D4;
pitchSantanninoPuzza[1]=NOTE_D4;
pitchSantanninoPuzza[2]=NOTE_G4;
pitchSantanninoPuzza[3]=NOTE_G4;
pitchSantanninoPuzza[4]=NOTE_G4;
pitchSantanninoPuzza[5]=NOTE_A4;
pitchSantanninoPuzza[6]=NOTE_G4;

pitchSantanninoPuzza[7]=NOTE_G4;
pitchSantanninoPuzza[8]=NOTE_A4;
pitchSantanninoPuzza[9]=NOTE_A4;
pitchSantanninoPuzza[10]=NOTE_G4;
pitchSantanninoPuzza[11]=NOTE_A4;
pitchSantanninoPuzza[12]=NOTE_B4;

pitchSantanninoPuzza[13]=NOTE_G4;
pitchSantanninoPuzza[14]=NOTE_D5;
pitchSantanninoPuzza[15]=NOTE_B4;
pitchSantanninoPuzza[16]=NOTE_G4;
pitchSantanninoPuzza[17]=NOTE_B4;
pitchSantanninoPuzza[18]=NOTE_D5;
pitchSantanninoPuzza[19]=NOTE_B4;
pitchSantanninoPuzza[20]=NOTE_G4;
pitchSantanninoPuzza[21]=NOTE_B4;
pitchSantanninoPuzza[22]=NOTE_A4;
pitchSantanninoPuzza[23]=NOTE_B4;
pitchSantanninoPuzza[24]=NOTE_A4;
pitchSantanninoPuzza[25]=NOTE_E4;
pitchSantanninoPuzza[26]=NOTE_G4;

pitchSantanninoPuzza[27]=NOTE_D4;
pitchSantanninoPuzza[28]=NOTE_D4;
pitchSantanninoPuzza[29]=NOTE_G4;
pitchSantanninoPuzza[30]=NOTE_G4;
pitchSantanninoPuzza[31]=NOTE_G4;
pitchSantanninoPuzza[32]=NOTE_A4;
pitchSantanninoPuzza[33]=NOTE_G4;

pitchSantanninoPuzza[34]=NOTE_G4;
pitchSantanninoPuzza[35]=NOTE_A4;
pitchSantanninoPuzza[36]=NOTE_A4;
pitchSantanninoPuzza[37]=NOTE_G4;
pitchSantanninoPuzza[38]=NOTE_A4;
pitchSantanninoPuzza[39]=NOTE_B4;

pitchSantanninoPuzza[40]=NOTE_G4;
pitchSantanninoPuzza[41]=NOTE_D5;
pitchSantanninoPuzza[42]=NOTE_B4;
pitchSantanninoPuzza[43]=NOTE_G4;
pitchSantanninoPuzza[44]=NOTE_B4;
pitchSantanninoPuzza[45]=NOTE_D5;
pitchSantanninoPuzza[46]=NOTE_B4;
pitchSantanninoPuzza[47]=NOTE_G4;
pitchSantanninoPuzza[48]=NOTE_B4;
pitchSantanninoPuzza[49]=NOTE_A4;
pitchSantanninoPuzza[50]=NOTE_B4;
pitchSantanninoPuzza[51]=NOTE_A4;
pitchSantanninoPuzza[52]=NOTE_E4;
pitchSantanninoPuzza[53]=NOTE_G4;

pitchSantanninoPuzza[54]=NOTE_G4;
pitchSantanninoPuzza[55]=NOTE_D5;
pitchSantanninoPuzza[56]=NOTE_B4;
pitchSantanninoPuzza[57]=NOTE_G4;
pitchSantanninoPuzza[58]=NOTE_B4;
pitchSantanninoPuzza[59]=NOTE_D5;
pitchSantanninoPuzza[60]=NOTE_B4;
pitchSantanninoPuzza[61]=NOTE_G4;
pitchSantanninoPuzza[62]=NOTE_B4;
pitchSantanninoPuzza[63]=NOTE_A4;
pitchSantanninoPuzza[64]=NOTE_B4;
pitchSantanninoPuzza[65]=NOTE_A4;
pitchSantanninoPuzza[66]=NOTE_E4;
pitchSantanninoPuzza[67]=NOTE_G4;
}

void playSantanninoPuzza() {
  currentDuration = durationSantanninoPuzza;
  currentPitch = pitchSantanninoPuzza;
  currentPos = 0;
  currentLen = sizeof(durationSantanninoPuzza) / sizeof(durationSantanninoPuzza[0]);
  currentScale = scaleSantanninoPuzza;
  currentTransport = transportSantanninoPuzza;
}
