#include <std.h>
#include <daemons.h>
#define WEATHER ({ "clear","partly cloudy", \
		   "mostly cloudy", "very cloudy", \
		   "lightly", "moderately", "heavily" })

string climate;
int weather;
int max_weather;

void Do_Weather();
void adjust_weather();
void set_climate(string str);

void set_climate(string str){ climate = str;}

mixed Check_Weather(){
	if(!climate) return 0;
	if(weather > 3){
		if((season(time()) == "winter") || (climate == "arctic"))
		return "%^BOLD%^%^WHITE%^It is snowing "+WEATHER[weather]+".%^RESET%^";
		else
		return "%^BOLD%^%^BLUE%^It is raining "+WEATHER[weather]+".%^RESET%^";
	}
	else 
	return "%^BOLD%^%^CYAN%^It is "+WEATHER[weather]+".";
}

void Do_Weather(){
     	if(!climate) return;
     	switch(climate){
		case "temperate":{
			max_weather = 6;
			if(random(100) < 40)
				adjust_weather();
		}
		case "arctic":{
			max_weather = 6;
			if(random(100) < 40)
				adjust_weather();
		}
		case "tropical":{
			max_weather = 6;
			if(random(100) < 80)
				adjust_weather();
		}
		case "desert":{
			max_weather = 2;
			if(random(100) < 10)
				adjust_weather();
		}
		default: return;
	}

}

void adjust_weather(){
    int temp;
	switch(season(time())){
		case "summer": temp = 3; break; 
		case "autumn": temp = 5; break;
		case "winter": temp = 4; break;
		case "spring": temp = 5; break;
		default: return;
	}
	if(random(10) < temp) {
		if(weather == max_weather) { weather--; return; }
		weather++;
	}
	else {
		if(weather == 0) return;
		weather--;
	}
}
