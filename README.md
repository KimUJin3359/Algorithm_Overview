# Overview

### 복잡도 분석
- 공간 복잡도 : 얼마나 많은 메모리 공간을 사용하는가
- 시간 복잡도 : 얼마나 많은 시간을 사용하는가
- 복잡도의 점근적 표기
  - 입력 크기 n이 무한대로 커질 떄의 복잡도를 간단히 표현하기 위해 사용
  - O(Big-O)
    - 점근적 상한을 표기
    - ex) 복잡도가 f(n) = 3n^3 - 4n^2 + 5n - 6이라면, f(n)의 O-표기는 O(n^3)
  - Ω(BIg-Omega)
    - 점근적 하한을 표기
    - f(n) = 2n^2 - 7n + 4의 Ω-표기는 Ω(n^2)
    - n이 증가함에 따라 2n^2 - 7n + 4이 cn^2보다 작을 수 없음을 의미
    - '최소한 이만한 시간은 걸린다'
  - Θ(Theta)
    - O-표기와 Ω-표기가 같은 경우에 사용
    - f(n) = Θ(n^2)은 n이 증가함에 따라 n^2과 동일한 증가율을 가진다는 의미
    
### 자주 사용하는 O-표기
- O(1) : 상수 시간(constant time)
  - 해쉬
- O(log n) : 로그 시간(Logarithmic time)
- O(n) : 선형시간 (linear time)
  - 순차 검색
- O(nlog n) : 로그 선형 시간(Log-linear time)
  - quick sort, merge sort, heap sort
- O(n^2) : 제곱 시간 (Quadratic time)
  - bubble sort, insertion sort, selection sort
- O(n^3) : 세제곱 시간 (Cubic time)
  - 플로이드-워셜
- O(2^n) : 지수 시간 (Exponential time)
  - 배낭문제, 부분집합
- O(n!)
  - 여행사 경로, 순열 등

### 표준 입출력 함수
- C
  - printf : 표준 출력 스트림에 출력
  - scanf : 표준 입력 스트림으로 입력
  - getc : 주어진 스트림으로부터 문자를 읽고 리턴
  - getchar : getc(stdin)과 같은 효과
  - putc : 스트림에 문자를 씀
  - putchar : putc(stdout)과 같은 효과
  - gets : stdin이 개행문자를 발생시키고 인수에 저장할 때까지 문자를 읽음
  - puts : stdout에 문자, 문자열을 출력
- C++
  - cin : 표준 입력(키보드)
  - cout : 표준 출력(화면에 출력)
  - width(int w) : 최소 필드 너비를 지정
  - precision(int p) : 유효 자리수를 설정
  - fill(char c) : c가 채워지는 문자가 되고, 함수의 결과로서 이전의 문자가 변환
- Java
  - 표준입출력
    - System.in, System.out, System.err
  - 표준입출력의 대상 변경
    - setOut(), setErr(), setIn()
    
### 비트 연산자
- & : 비트단위로 and 연산
- | : 비트단위로 or 연산
- ^ : 비트단위로 xor 연산
- ~ : 단한 연상자로서 피연산자의 모든 비트를 반전(not)
- <<, >> : 비트 열 이동
- 엔디안(Endianness)
  - 메모리에 여러 개의 연속된 대상을 배열하는 방법
  - 빅 엔디안
    - 보통 큰 단위가 앞에 나옴(네트워크)
    - 0x12345678 -> 12 34 56 78
  - 리틀 엔디안
    - 작은 단위가 앞에 나옴(대다수 데스크탑)
    - 0x12345678 -> 78 56 34 12
- Structure Byte Padding
  - 구조체 멤버들 사이에 임의의 공간이 생기는 현상
  - 구조체의 경우 멤버 중 가장 큰 데이터 타입의 배수 값으로 크기가 결정
- 패킹과 언패킹
```
int pack(char a, char b, char c, char d)
{
  int p = a;
  p = (p << 8) | b;
  p = (p << 8) | c;
  p = (p << 8) | d;
  return (p);
}

char unpack(int p, int k)
{
  int n = k * 8;
  unsigned mask = 255;
  mask <<= n;
  return ((p & mask) >> n);
}
```

### 진수

### 실수
- 컴퓨터는 실수를 표현하기 위해 부동 소수점(floating-pint) 표기법을 사용
- 단정도 실수(32비트) : 부호 1비트 / 지수 8비트 / 가수 23비트
- 배정도 실수(64비트) : 부호 1비트 / 지수 11비트 / 가수 52비트
- 컴퓨터는 실수를 근사적으로 표현
  - 이진법으로 표현 할 수 없는 형태의 실수는 정확한 값이 아니라 **근사 값**으로 저장되는데 이 때 생기는 작은 오차가 계산 과정에서 다른 결과를 생성
  
#### 관련 문제
[1.Simple Password](https://github.com/KimUJin3359/Overview/tree/master/SimplePassword)
- 암호 코드의 [규칙]()이 링크와 같음
- 세로 50, 가로 100 이하의 크기를 가진 직사각형 배열에 암호코드 정보가 포함되어 전달(정상일수도 비정상일수도 있음)
- 암호코드 정보를 확인하고, 정상적인 암호코드인지 확인
- 암호코드들에 적혀있는 숫자들의 합을 출력
- 암호 코드의 [세부 규칙]()은 링크와 같음
- 접근 방법
  - will update

[2.Password Scan]()
- to be continued

[3.ex01](https://github.com/KimUJin3359/Overview/tree/master/ex01)
- 0과 1로 이루어진 1차 배열에서 7개 bit를 묶어 10진법으로 출력하는 문제

[4.ex02](https://github.com/KimUJin3359/Overview/tree/master/ex02)
- 16진수 문자로 이루어진 1차 배열에서 앞에서부터 7bit씩 묶어 십진수로 변환하여 출력하는 문제

[5.ex03](https://github.com/KimUJin3359/Overview/tree/master/ex03)
- 16진수 문자로 이루어진 1차 배열이 주어질 때, 암호비트 패턴을 찾아 순서대로 출력
- 암호비트는 2진법으로 구성됨

