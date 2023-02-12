int **checkValidity(int credCard[][16])
{
    int resultCard[10000][18], x, y, sum, digitSum[16];

    for(x = 0; x < 10000; x++){
        for(y = 0; y < 16; y++){
            resultCard[x][y] = credCard[x][y];
        }
    }

    for(x = 0; x <10000; x++){
        for(y = 0; y < 16; y++){
            if(y % 2 == 0){
                if(credCard[x][y] * 2 > 10){
                    digitSum[y] = credCard[x][y] * 2 % 10 + 1;
                } else {
                    digitSum[y] = credCard[x][y] * 2
                }
            } else {
                digitSum[y] = credCard[x][y];
            }
        }
        for(idx = sum = 0; idx < 16; idx++){
            sum += digitSum[idx];
        }
        resultCard[x][16] = (sum % 10 == 0) ? 'V' : 'I';
        resultCard[x][17] = -1;
    }

    return resultCard;
}