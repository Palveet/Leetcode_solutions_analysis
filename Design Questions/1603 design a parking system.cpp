class ParkingSystem {
public:
int Big = 0;
int Medium = 0;
int Small = 0;
    ParkingSystem(int big, int medium, int small) {
        Big = big;
        Medium = medium;
        Small = small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && Big>0){
                Big--;
                return true;
        }
        if(carType==2 && Medium>0){
                Medium--;
                return true;
        }
        if(carType==3 && Small>0){
                Small--;
                return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

//TC:O(1)
//SC:O(1)