int pitchSonPerdenti[16], 
durationSonPerdenti[16]={500,500,500,500,500,500,250,750,500,500,500,500,500,500,250,750};
double scaleSonPerdenti = 1.0;
double transportSonPerdenti = 1.0;

void initSonPerdenti() {
pitchSonPerdenti[0]=NOTE_A4;
pitchSonPerdenti[1]=NOTE_F4;
pitchSonPerdenti[2]=NOTE_F4;
pitchSonPerdenti[3]=NOTE_D4;
pitchSonPerdenti[4]=NOTE_F4;
pitchSonPerdenti[5]=NOTE_F4;
pitchSonPerdenti[6]=NOTE_A4;
pitchSonPerdenti[7]=NOTE_A4;

pitchSonPerdenti[8]=NOTE_A4;
pitchSonPerdenti[9]=NOTE_F4;
pitchSonPerdenti[10]=NOTE_F4;
pitchSonPerdenti[11]=NOTE_D4;
pitchSonPerdenti[12]=NOTE_F4;
pitchSonPerdenti[13]=NOTE_G4;
pitchSonPerdenti[14]=NOTE_F4;
pitchSonPerdenti[15]=NOTE_F4;
}

void playSonPerdenti() {
  currentDuration = durationSonPerdenti;
  currentPitch = pitchSonPerdenti;
  currentPos = 0;
  currentLen = sizeof(durationSonPerdenti) / sizeof(durationSonPerdenti[0]);
  currentScale = scaleSonPerdenti;
  currentTransport = transportSonPerdenti;
}
