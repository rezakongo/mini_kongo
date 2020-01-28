#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<math.h>
#include <cstdlib>
#include <ctime>




int main()
{   
    float windarrow;
    float x1=250;
    float y1=570;
    float r1=0;
    float x2=700;
    float y2=570;
    float r2=0;
    float health_one=1;
    float health_tow=1;
    float power=0;
    float speed;
    float t;
    float xz;
    float yz;
    float x;
    float y;
    float r;
    float ri;
    float pi;
    sf::RenderWindow window(sf::VideoMode(1024, 728), "Mini Kongo");
    
    sf::Texture tank1Texture;
    tank1Texture.loadFromFile("Images/tank1.png");

    sf::Sprite tank1;
    tank1.setTexture(tank1Texture);
    tank1.setPosition(x1,y2);

    sf::Texture tank1gunTexture;
    tank1gunTexture.loadFromFile("Images/tank1gun.png");

    sf::Sprite tank1gun;
    tank1gun.setTexture(tank1gunTexture);
    tank1gun.setOrigin(0.f,5.f);
    tank1gun.setPosition(x1+50,y1+10);
    tank1gun.setRotation(r1);


    sf::Texture tank2Texture;
    tank2Texture.loadFromFile("Images/tank.png");

    sf::Sprite tank2;
    tank2.setTexture(tank2Texture);
    tank2.setPosition(x2,y2);

    sf::Texture tank2gunTexture;
    tank2gunTexture.loadFromFile("Images/tankgun.png");

    sf::Sprite tank2gun;
    tank2gun.setTexture(tank2gunTexture);
    tank2gun.setOrigin(60.f,5.f);
    tank2gun.setPosition(x2+45,y2+10);
    
    
    sf::Texture sceneTexture;
    sceneTexture.loadFromFile("Images/scene.png");

    sf::Sprite scene;
    scene.setTexture(sceneTexture);
    scene.setPosition(0.f,478.f);

    sf::Texture background;
    background.loadFromFile("Images/Sky.bmp");

    sf::Sprite back;
    back.setTexture(background);
    back.setPosition(0.f,0.f);

    sf::CircleShape bullet(3.f);
    bullet.setFillColor(sf::Color::Red);
    bullet.setOrigin(3.f,3.f);

    sf::Texture windTexture;
    windTexture.loadFromFile("Images/wind1.png");

    sf::Sprite wind;
    wind.setTexture(windTexture);
    wind.setPosition(512.f,70.f);
    

    sf::Texture scoreboardTexture;
    scoreboardTexture.loadFromFile("Images/scoreboard.png");

    sf::Sprite scoreboard;
    scoreboard.setTexture(scoreboardTexture);
    scoreboard.setPosition(0.f,0.f);


    sf::Texture health1Texture;
    health1Texture.loadFromFile("Images/health1.png");

    sf:: Sprite health1;
    health1.setTexture(health1Texture);
    health1.setPosition(45.f,70.f);
    health1.setScale(health_one,1.f);

    sf::Texture health2texture;
    health2texture.loadFromFile("Images/health2.png");

    sf::Sprite health2;
    health2.setTexture(health2texture);
    health2.setPosition(750.f,70.f);
    health2.setScale(health_tow,1.f);

    sf:: Texture powerTexture;
    powerTexture.loadFromFile("Images/power.png");

    sf:: Sprite powerChart;
    powerChart.setTexture(powerTexture);

    sf::Texture onewinTexture;
    onewinTexture.loadFromFile("Images/player1win.png");

    sf::Sprite player1win;
    player1win.setTexture(onewinTexture);
    player1win.setPosition(250.f,330.f);

    sf::Texture towwinTexture;
    towwinTexture.loadFromFile("Images/player2win.png");

    sf::Sprite player2win;
    player2win.setTexture(towwinTexture);
    player2win.setPosition(250.f,330.f);

    sf::SoundBuffer shootb;
    shootb.loadFromFile("sounds/gun.wav");

    sf::Sound shoot;
    shoot.setBuffer(shootb);
    
    sf::SoundBuffer explosionb;
    explosionb.loadFromFile("sounds/explosion.wav");

    sf::Sound explosion;
    explosion.setBuffer(explosionb);

    sf::SoundBuffer moveb;
    moveb.loadFromFile("sounds/truck.wav");

    sf::Sound move;
    move.setBuffer(moveb);

    
    while (window.isOpen())
    {   
        srand(time(NULL));
        windarrow=(rand()%20-10)/10;
        wind.setScale(windarrow,1.f);
        while(true){
        power=0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
            break;
        }
        
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close(); 
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            
            if(x1<=930){
            tank1.move(10.f,0.f);
            tank1gun.move(10.f,0.f);
            x1+=10;
            
            }
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if(x1>0){
            tank1.move(-10.f,0.f);
            tank1gun.move(-10.f,0.f);
            x1-=10;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(r1>-180){
                r1-=2;
                tank1gun.setRotation(r1);
            }
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(r1<0){
                r1+=2;
                tank1gun.setRotation(r1);
                }
            }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                if(power<=2)
                    power+=0.02;
                powerChart.setPosition(x1,y1-35);
                powerChart.setScale(power,1.f);
                window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(powerChart);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.display();
            }
        shoot.play();
        t=0;
        speed=power*20;

        xz=x1+50+60*cos(r1*(M_PI/180));
        yz=y1+10+60*sin(r1*(M_PI/180));
        x=0;
        y=0;
        while(y<600){
            t+=0.2;

            x=speed*cos(r1*(M_PI/180))*t+xz;
            y=(0.3*t*t)+speed*sin(r1*(M_PI/180))*t+yz;
            bullet.setPosition(x,y);
            window.clear();
            window.draw(back);
            window.draw(scene);
            window.draw(tank1gun);
            window.draw(tank1);
            window.draw(tank2gun);
            window.draw(tank2);
            window.draw(bullet);
            window.draw(scoreboard);
            window.draw(health1);
            window.draw(health2);
            window.draw(wind);
            window.display();
            if(x>x2&&x<x2+100&&y>y2&&y<y2+45){
                health_tow-=0.3;
                health2.setScale(health_tow,1.f);
                window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.display();
            break;
            }
        }
        explosion.play();
        
        window.clear();
        window.draw(back);
        window.draw(scene);
        window.draw(tank1gun);
        window.draw(tank1);
        window.draw(tank2gun);
        window.draw(tank2);
        window.draw(scoreboard);
        window.draw(health1);
        window.draw(health2);
        window.draw(wind);
        window.display();
        break;
        }
        

         window.clear();
        window.draw(back);
        window.draw(scene);
        window.draw(tank1gun);
        window.draw(tank1);
        window.draw(tank2gun);
        window.draw(tank2);
        window.draw(scoreboard);
        window.draw(health1);
        window.draw(health2);
        window.draw(wind);
        window.display();
        
    
    }

    if(health_tow<=0.f){
            while(true){
                window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.draw(player1win);
                window.display();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }}
        }

        srand(time(NULL));
        windarrow=(rand()%20-10)/10;
        wind.setScale(windarrow,1.f);
     while(true){
        power=0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close(); 
        }
        
        if((x2-x1)>900&&(x2-x1)<1024){
            ri=40;
            pi=1;
        }else if((x2-x1)>800&&(x2-x1)<900){
            ri=32;
            pi=1;
        }else if((x2-x1)>700&&(x2-x1)<800){
            ri=35;
            pi=0.9;
        }else if((x2-x1)>600&&(x2-x1)<700){
            ri=35;
            pi=0.9;
        }else if((x2-x1)>500&&(x2-x1)<600){
            ri=35;
            pi=0.85;
        }else if((x2-x1)>400&&(x2-x1)<500){
            ri=30;
            pi=0.8;
        }else if((x2-x1)>300&&(x2-x1)<400){
            ri=30;
            pi=0.6;
        }else if((x2-x1)>200&&(x2-x1)<300){
            ri=30;
            pi=0.5;
        }else if((x2-x1)>100&&(x2-x1)<200){
            ri=25;
            pi=0.5;
        }else if((x2-x1)>0&&(x2-x1)<100){
            ri=0;
            pi=0.8;
        }else if((x2-x1)>-100&&(x2-x1)<0){
            ri=180;
            pi=0.9;
        }else if((x2-x1)>7-200&&(x2-x1)<-100){
            ri=155;
            pi=0.4;
        }else if((x2-x1)>-300&&(x2-x1)<-200){
            ri=150;
            pi=0.5;
        }else if((x2-x1)>-400&&(x2-x1)<-300){
            ri=150;
            pi=0.6;
        }else if((x2-x1)>-500&&(x2-x1)<-400){
            ri=145;
            pi=0.7;
        }else if((x2-x1)>-600&&(x2-x1)<-500){
            ri=142;
            pi=0.8;
        }else if((x2-x1)>-800&&(x2-x1)<-700){
            ri=140;
            pi=0.8;
        }else if((x2-x1)>-900&&(x2-x1)<-800){
            ri=140;
            pi=0.8;
        }else if((x2-x1)>-1024&&(x2-x1)<-900){
            ri=140;
            pi=0.8;
        }


        while(r2<ri){
            tank2gun.setRotation(r2);
            r2+=2;
                window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.display();
        }while(r2>ri){

            tank2gun.setRotation(r2);
            r2-=2;
            window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.display();
                }
            while(power<pi){
                
                    power+=0.02;
                powerChart.setPosition(x2,y2-35);
                powerChart.setScale(power,1.f);
                window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(powerChart);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.display();
            }
        shoot.play();
        t=0;
        speed=power*20;

        xz=x2+45+60*cos((180-r2)*(M_PI/180));
        yz=y2+10-60*sin((180-r2)*(M_PI/180));
        x=0;
        y=0;
        while(y<600){
            t+=0.2;

            x=speed*cos((180-r2)*(M_PI/180))*t+xz;
            y=(0.3*t*t)-speed*sin((180-r2)*(M_PI/180))*t+yz;
            bullet.setPosition(x,y);
            window.clear();
            window.draw(back);
            window.draw(scene);
            window.draw(tank1gun);
            window.draw(tank1);
            window.draw(tank2gun);
            window.draw(tank2);
            window.draw(bullet);
            window.draw(scoreboard);
            window.draw(health1);
            window.draw(health2);
            window.draw(wind);
            window.display();
            if(x>x1&&x<x1+100&&y>y1&&y<y1+45){
                health_one-=0.1;
                health1.setScale(health_one,1.f);
                window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.display();
            break;
            }
        }
        explosion.play();
        window.clear();
        window.draw(back);
        window.draw(scene);
        window.draw(tank1gun);
        window.draw(tank1);
        window.draw(tank2gun);
        window.draw(tank2);
        window.draw(scoreboard);
        window.draw(health1);
        window.draw(health2);
        window.draw(wind);
        window.display();
        break;
        

         window.clear();
        window.draw(back);
        window.draw(scene);
        window.draw(tank1gun);
        window.draw(tank1);
        window.draw(tank2gun);
        window.draw(tank2);
        window.draw(scoreboard);
        window.draw(health1);
        window.draw(health2);
        window.draw(wind);
        window.display();
        
    
        }
       
     if(health_one<=0.f){
            while(true){
                window.clear();
                window.draw(back);
                window.draw(scene);
                window.draw(tank1gun);
                window.draw(tank1);
                window.draw(tank2gun);
                window.draw(tank2);
                window.draw(scoreboard);
                window.draw(health1);
                window.draw(health2);
                window.draw(wind);
                window.draw(player2win);
                window.display();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            
            }
        }

    }
     

    return 0;
}