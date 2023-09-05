   Room()
    {
      strcpy(roomtype,"") ;
        rcode=0;
        flag=0;
        price=0;
        discount=0;
        VAT=0;
        for (int i = 0; i < 20; ++i) {
            special_feature[i] = "";
        }
    }