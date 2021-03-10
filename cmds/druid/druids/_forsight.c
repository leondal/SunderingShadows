// Pator@ShadowGate
// June 14 1996
// A check for the worships

int cmd_forsight();
int wcount();

int cmd_forsight() {
string str;
      str="%^BOLD%^";
	switch(wcount()) {
	case  0..14 : str+="%^RED%^Thy diety is unaware of your loyalty";
		        break;
	case 15..29 : str+="%^RED%^Thy diety notices a feeling of devotion";
			break;
	case 30..49 : str+="%^BLUE%^Thy diety arrives at your horizon";
			break;
	case 50..69 : 
	str+="%^BLUE%^Thou art filled with hope for divine bestowal";
		break;
	case 70..89 : 
	str+="%^GREEN%^Thy diety peers at you and finds you unworthy still!";
	 break;
	case 90..99 : 
	str+="%^GREEN%^Thy diety will grant you a spell very soon!";
		break;
		}
    str+="%^RESET%^";
	tell_object(this_player(), str);
	return 1; }

int wcount() {
object ob;
int worship, interval, count;
	ob = present("mistletoe", this_player());
	worship = (int)ob->query_worship();
	interval = (int)ob->query_interval();
	count = (100*worship)/interval;
	return count; }
