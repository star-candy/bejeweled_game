
# ��� ���

## puzzle.cpp/.h �����ϱ�

  + [0] getjewelLetter (���� type�� �´� text ��ȯ) 
  + [0] getJewlType (text �Է½� �Է¿� �ش��ϴ� ���� type ��ȯ)
	
  + [0] puzzle constructor (������ ����, ���� ������ ���ڷ� ����, �� + �� ũ�⸦ vector ũ���)
	+ ��� jewel �� NONE���� �ʱ�ȭ
	+ vector ���� jewels
	
  + [0] initialize (�Է¹��� jewel_list_���ڿ��� ���� ��� jewel�� �ʱ�ȭ)
	+ jewel_list���ڿ��� getJewelType�� ���� jewel type���� ����_
	+ jewel vector�� jewel_list���� ����ġ�� false return_
	
  + [0] randomize (��� jewel�� �����ϰ� �ʱ�ȭ)
	+ rand�� enum ��ü �������� int�� jewel type ��ȯ
	
  + [0] update (chain ���� �� jewel vector�� update ����)
	+ A : ��� ü�� �ĺ�(����, ���� ����), NONE type���� ����
		+ [0] validCount : �˻� ������ jewels vector �������� �Ǵ�
		+ [0] identifyChain : jewels vector ��ü�� ���� type�� ��ǥ ���� ����
		+ [0] createChain : countChain ������ ���� chain ���� �� pushback
		+ [0] countChain : ����, ���� ��ġ�� ���� Ÿ�� ���� ���� ����
		+ [0] claerChain : chain ��ǥ�� ���Ե� jewels�� type�� NONE���� ����
	+ B : NONE type jewel�� ���� ���� ����߷� ä���, ���� ������� �����ϰ� �ſ��
		+ [0] fillJewels : none type�� jewels�� �����ϰ� �� ä���ֱ�
	+ update ȣ�� �� A, B ��� �� �ϳ� ����
	+ A B ����� ����ȴٸ� true, chain�� ���� �� false ��ȯ
	
  + [0] coordinateValidate (��ǥ �޾Ƽ� ��ȿ�� �˻�, setJewel, getJewel, swapJewel ���) 

  + [0] setJewel (���� ��ǥ, jewel ������ ���ڷ� �޾� ���� ���� ����)
	+ ��ǥ�� ����, Ȥ�� jewel vector�� ũ�� �ܺο� ���� �� false ��ȯ
	+ vector ���ο� ���� �� ���� �� true ��ȯ

  + [0] getJewel (���� ��ǥ�� ���ڷ� ����)
	+ ��ǥ ��ȿ �� �ش� ��ǥ�� ���� type�� return
	+ ����ȿ ��ǥ �� NONE type�� return
	
  + [0] swapJewels (swap ���� ���� ��ǥ 2���� ���ڷ� ����)
	+ ��ǥ ��ġ ����(jewel vector ���� �ִ°�, �� ��ġ�� �����Ѱ�)->false ��ȯ
	+ jewels vector���� �� ��ǥ�� type swap -> true ��ȯ

	--------------------------------------------------------------------------------------

## ����� ui �����ϱ�

## text based bejeweled ���� ����

- main_text.cpp
- Text_Puzzle class

   + [0] constructor (������ ����, ���� ������ ���ڷ� ����, �� + �� ũ�⸦ vector ũ���)
	 + ��� jewel �� NONE���� �ʱ�ȭ
	 + vector ���� jewels

  + [0]  createTextJewels (Jewel type�� jewels vector�� text vector�� ��ȯ�ϴ� ���)
	
  + [0] printTextJewels (���Ŀ� �°� text vector ���)
	+ �� ������ ����ؼ� ���Ŀ� �°� ����
	
  + [0] initialScreen (���� �ʱ� ȭ�鿡���� �Է� ���� �� jewels ������ ���) 
	+ ���� �ʱ� ���� ��� �� �Է°� ����
	+ �Է� ���� �°� jewel �ʱ�ȭ �� �� ���
	+ �ʱⰪ�� chain�� �߻� �� jewels ���� ���
  
  + [0] swapScreen(���� ��ǥ ���� �� jewels ����)
	+ ���� �̵� ���� ��ǥ���� ����
	+ ���� �� chain �߻� �� ���� ���� ���


