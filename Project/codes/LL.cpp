void Scene::callHero() 
{ 
    tmMyHero-> start(1000); 
    qsrand(qrand()); 
    hero_type = qrand()%NUM_HERO + 1; 
    /*tmMyHero-> timeout(200); 
     隱藏避免耗時過久*/ 
    switch(hero_type){ 
        case 1: 
        if(myHero_1->isVisible()) 
            goto reChoose; 
        else{ 
            addItem(myHero_1); 
            QObject::connect(tmMyHero, SIGNAL(timeout()), &Minion, SLOT(moveMyHero(myHero_1)); 
            break; 
        } 
        case 2: 
        if(myHero_2->isVisible()) 
            goto reChoose; 
        else{ 
            addItem(myHero_2); 
            QObject::connect(tmMyHero, SIGNAL(timeout()), &Minion, SLOT(moveMyHero(myHero_2)); 
            break; 
        } 
        case 3: 
        if(myHero_3->isVisible()) 
            goto reChoose; 
        else{ 
            addItem(myhHero_3); 
            QObject::connect(tmMyHero, SIGNAL(timeout()), &Minion, SLOT(moveMyHero(myHero_3)); 
            break; 
        } 
        case 4: 
        if(myHero_4->isVisible()) 
            goto reChoose; 
        else{ 
            addItem(myHero_4); 
            QObject::connect(tmMyHero, SIGNAL(timeout()), &Minion, SLOT(moveMyHero(myHero_4)); 
            break; 
        } 
        case 5: 
        if(myHero_5->isVisible()) 
            goto reChoose; 
        else{ 
            addItem(myHero_5); 
            QObject::connect(tmMyHero, SIGNAL(timeout()), &Minion, SLOT(moveMyHero(myHero_5)); 
            break; 
        } 
     } 
    reChoose: 
        hero_type = qrand()%NUM_HERO + 1; 
}