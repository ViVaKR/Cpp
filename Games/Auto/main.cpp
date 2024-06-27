#include <chrono>
#include <iostream>
#include <thread>

class AutonomousCar
{
  private:
    double speed;              // 자동차의 속도
    double distanceToObstacle; // 장애물과의 거리

  public:
    // 생성자
    AutonomousCar(double initialSpeed, double distance) : speed(initialSpeed), distanceToObstacle(distance) {}

    // 공주거리 공주
    double freeRuntimeDistance()
    {
        return (speed * 1.0) / 3.6;
    }

    // 제동 거리 계산
    double brakingDistance()
    {
        return 0.005 * pow(speed, 2.0) + 0.2 * speed;
    }

    // 속도 설정
    void setSpeed(double newSpeed)
    {
        speed = newSpeed;
    }

    // 장애물까지의 거리 설정
    void setDistanceToObstacle(double newDistance)
    {
        distanceToObstacle = newDistance;
    }

    bool start()
    {
        int checkRatio = 10;                              // 체크 비율
        int second = 1000;                                // 1초
        double _totalDistance = freeRuntimeDistance() + brakingDistance();
        double moveDistanceForRatio = speed / checkRatio; // 속도에 따른 이동거리 계산

        // 자율주행 시율
        while (true) {
            distanceToObstacle -= moveDistanceForRatio; // 장애물까지의 거리 갱신
            printStatus();                              // 현재 상태 출력

            std::this_thread::sleep_for(std::chrono::milliseconds(second / checkRatio));

            // 물첵과의 거리가 제동거리 범위 내에 들어왔을 때
            if (_totalDistance * 2 >= distanceToObstacle) {
                std::cout
                    << "\n\033[031m\u2757 (Warning) 전방에 근접 물체 발견 \033[0m"
                    << std::endl; // 경고 메시지 출력

                std::cout
                    << "현재 주행속도의 제동거리 ( \033[31m"
                    << round(_totalDistance)
                    << "\033[0m ) 약 2배 거리 내에 ( \033[31m"
                    << distanceToObstacle
                    << "\033[0m ) 미확인 물체(UFO)가 발견!"
                    << std::endl; // 제동 개시 안내

                std::cout
                    << "\033[033m\u26DF\t속도 ("
                    << speed
                    << ") 를 절반으로 감속 시행...\033[0m"
                    << std::endl;    // 속도 절반으로 줄임 안내

                setSpeed(speed / 2); // 속도 절반으로 줄임
                distanceToObstacle -= moveDistanceForRatio * 3;
                std::this_thread::sleep_for(std::chrono::milliseconds(second / checkRatio));
                if (distanceToObstacle <= (_totalDistance / 2)) {
                    speed = 0;
                    std::cout << "자동차를 무사히 정지하였습니다.." << std::endl;
                    return true;
                }
            }
        }

        return false;
    }

    // 자율주행 시뮬레이션
    void autonomousDrive()
    {
        // 공주거리 계산
        double _freeRuntimeDistance = freeRuntimeDistance();
        std::cout << "공주거리: " << round(_freeRuntimeDistance) << "m" << std::endl;

        // 제동거리 계산
        double _brakingDistance = brakingDistance();
        std::cout << "제동거리: " << round(_brakingDistance) << "m" << std::endl;

        // 총 제동거리 (공주거리 + 제동거리)
        double _totalDistance = freeRuntimeDistance() + brakingDistance();
        std::cout << "총 제동거리: " << _totalDistance << "m" << std::endl;

        std::cout << "자율주행을 시작합니다. 부릉부릉 ~~ " << std::endl;

        std::cout << "전방 -> "
                  << round(distanceToObstacle)
                  << "m 지점에 장애물이 있습니다. 제동거리를 고려하여 안전운행하세요." << std::endl;
    }

    // 현재 상태 출력
    void printStatus()
    {
        std::cout << "현재 속도: \033[1;035m" << speed << " m/s\033[0m, 장애물과의 거리: \033[1;035m" << distanceToObstacle << " m\033[0m" << std::endl;
    }

    // 장애물에 도달 여부 확인
    bool obstacleReached()
    {
        return distanceToObstacle <= 5; // 장애물과의 거리가 5m 이내일 때 true 반환
    }
};

int main()
{
    double initialSpeed;   // 초기 속도
    double distance = 400; // 장애물과의 거리
    std::cout << "\u2766 자율주행자동차의 초기 속도를 입력하세요 (m/s): ";
    std::cin >> initialSpeed;

    // 자율주행자동차 객체 생성
    AutonomousCar car(initialSpeed, distance);

    car.autonomousDrive();     // 자율주행 시뮬레이션
    bool result = car.start(); // 자동차 이동

    std::cout << "자율 주행 결과 \u2728" << (result ? "차량 출시 준비완료!" : "연구가 더 필요함!") << std::endl;

    return 0;
}
