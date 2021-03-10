int roll_dice(int num, int sides) {
  int x,cnt;
  
  cnt = 0;
  for(x=0;x<num;x++) {
    cnt += random(sides)+1;
  }
  return cnt;
}