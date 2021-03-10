void sort(string *stuff);
private void swap(int i, int j, string *stuff);

void sort(string *stuff){
    int i,j;

    for(j=0;j<sizeof(stuff);j++) {
      for(i=sizeof(stuff)-1;i>j;i--){
        if(!stringp(stuff[i-1])) continue;
        if(stuff[i] < stuff[i-1]){
          swap(i-1,i,stuff);
        }
      }
    }
}

private void swap(int i, int j, string* stuff){
	string tmp;
	tmp = stuff[i];
	stuff[i]=stuff[j];
	stuff[j]=tmp;
}
