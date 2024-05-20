
# 기능 목록

## puzzle.cpp/.h 구현하기

  + [0] getjewelLetter (보석 type에 맞는 text 반환) 
  + [0] getJewlType (text 입력시 입력에 해당하는 보석 type 반환)
	
  + [0] puzzle constructor (게임의 가로, 세로 개수를 인자로 받음, 행 + 열 크기를 vector 크기로)
	+ 모든 jewel 을 NONE으로 초기화
	+ vector 명은 jewels
	
  + [0] initialize (입력받은 jewel_list_문자열을 통해 모든 jewel을 초기화)
	+ jewel_list문자열은 getJewelType을 통해 jewel type으로 변경_
	+ jewel vector와 jewel_list길이 불일치시 false return_
	
  + [0] randomize (모든 jewel을 랜덤하게 초기화)
	+ rand와 enum 객체 생성으로 int와 jewel type 전환
	
  + [0] update (chain 존재 시 jewel vector에 update 진행)
	+ A : 모든 체인 식별(수직, 수평 포함), NONE type으로 변경
		+ [0] validCount : 검사 범위가 jewels vector 범위인지 판단
		+ [0] identifyChain : jewels vector 전체에 대한 type과 좌표 정보 제공
		+ [0] createChain : countChain 정보를 통해 chain 생성 및 pushback
		+ [0] countChain : 가로, 세로 위치에 같은 타입 개수 정보 제공
		+ [0] claerChain : chain 좌표에 포함된 jewels의 type을 NONE으로 변경
	+ B : NONE type jewel을 상위 보석 떨어뜨려 채우고, 위쪽 빈공간은 랜덤하게 매운다
		+ [0] fillJewels : none type인 jewels에 랜덤하게 값 채워넣기
	+ update 호출 시 A, B 기능 중 하나 실행
	+ A B 기능이 실행된다면 true, chain이 없을 시 false 반환
	
  + [0] coordinateValidate (좌표 받아서 유효성 검사, setJewel, getJewel, swapJewel 사용) 

  + [0] setJewel (보석 좌표, jewel 종류를 인자로 받아 보석 종류 수정)
	+ 좌표가 음수, 혹은 jewel vector의 크기 외부에 있을 시 false 반환
	+ vector 내부에 존재 시 변경 후 true 반환

  + [0] getJewel (보석 좌표를 인자로 받음)
	+ 좌표 유효 시 해당 좌표의 보슥 type을 return
	+ 비유효 좌표 시 NONE type을 return
	
  + [0] swapJewels (swap 위한 보석 좌표 2개를 인자로 받음)
	+ 좌표 위치 검증(jewel vector 내에 있는가, 두 위치가 인접한가)->false 반환
	+ jewels vector에서 두 좌표의 type swap -> true 반환

	--------------------------------------------------------------------------------------

## 사용자 ui 구현하기

## text based bejeweled 게임 구현

- main_text.cpp
- Text_Puzzle class

   + [0] constructor (게임의 가로, 세로 개수를 인자로 받음, 행 + 열 크기를 vector 크기로)
	 + 모든 jewel 을 NONE으로 초기화
	 + vector 명은 jewels

  + [0]  createTextJewels (Jewel type인 jewels vector를 text vector로 변환하는 기능)
	
  + [0] printTextJewels (형식에 맞게 text vector 출력)
	+ 열 단위로 출력해서 형식에 맞게 구성
	
  + [0] initialScreen (게임 초기 화면에서의 입력 수행 및 jewels 변형해 출력) 
	+ 게임 초기 문구 출력 및 입력값 검증
	+ 입력 값에 맞게 jewel 초기화 및 값 출력
	+ 초기값에 chain이 발생 시 jewels 변경 출력
  
  + [0] swapScreen(변경 좌표 검증 및 jewels 변경)
	+ 정상 이동 가능 좌표인지 검증
	+ 검증 후 chain 발생 시 변경 내용 출력


