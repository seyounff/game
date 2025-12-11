# 🎮 Unreal Engine 5 설치 및 환경 설정 (11/28)

## 📌 개요

이 문서는 Unreal Engine 5의 기초 개념과 설치 및 환경 설정 과정을 정리한 내용입니다.

---

## 🚀 주요 학습 내용

### 1. Unreal Engine 5 소개

#### 1.1 Unreal Engine이란?

* Epic Games에서 개발한 고성능 게임 엔진
* AAA급 게임부터 인디 게임까지 다양한 프로젝트에 활용
* 실시간 3D 렌더링, 물리 엔진, 애니메이션 등 통합 제공

#### 1.2 주요 특징

* **Nanite**: 초고해상도 지오메트리 시스템
* **Lumen**: 동적 글로벌 일루미네이션 시스템
* **Blueprint**: 비주얼 스크립팅 시스템
* **C++ 지원**: 고급 프로그래밍 가능

---

## 💻 설치 및 환경 설정

### 2.1 시스템 요구사항

#### 최소 사양

| 항목 | 요구사항 |
|------|----------|
| **OS** | Windows 10 64-bit |
| **프로세서** | Quad-core Intel or AMD, 2.5 GHz 이상 |
| **메모리** | 8 GB RAM |
| **그래픽카드** | DirectX 11/12 호환 |

#### 권장 사양

| 항목 | 요구사항 |
|------|----------|
| **OS** | Windows 10/11 64-bit |
| **프로세서** | 8-core Intel or AMD, 3+ GHz |
| **메모리** | 32 GB RAM |
| **그래픽카드** | NVIDIA RTX 2080 이상 / AMD 동급 |
| **저장공간** | SSD 256 GB 이상 |

### 2.2 설치 과정

#### Step 1: Epic Games Launcher 설치

1. [Epic Games 공식 웹사이트](https://www.epicgames.com/) 접속
2. Epic Games Launcher 다운로드
3. 설치 프로그램 실행 및 계정 생성/로그인

#### Step 2: Unreal Engine 5 설치

1. Epic Games Launcher 실행
2. 왼쪽 메뉴에서 **Unreal Engine** 선택
3. 상단의 **엔진 버전** 탭 클릭
4. **+ 버튼** 클릭하여 Unreal Engine 5.x 설치
5. 설치 위치 선택 후 **설치** 버튼 클릭

#### Step 3: 프로젝트 생성

1. Launcher에서 **실행** 버튼 클릭
2. 프로젝트 브라우저에서 템플릿 선택
   * **게임** 카테고리: Third Person, First Person 등
   * **필름/비디오 & 라이브 이벤트**: 영상 제작용
3. 프로젝트 설정
   * Blueprint 또는 C++ 선택
   * 타겟 플랫폼 (Desktop, Mobile 등)
   * 품질 설정 (Maximum Quality, Scalable)
4. **프로젝트 생성** 클릭

### 2.3 초기 환경 설정

#### 에디터 언어 변경

1. **Edit → Editor Preferences**
2. **General → Internationalization**
3. **Editor Language**를 원하는 언어로 선택
4. 에디터 재시작

#### 뷰포트 설정

* **마우스 조작**
  * 우클릭 + WASD: 자유 이동
  * 좌클릭 드래그: 팬 이동
  * 스크롤: 줌 인/아웃
* **그리드 스냅**: 오브젝트 정렬 시 사용

---

## 📚 에디터 기본 구조

### 주요 패널

| 패널 | 설명 |
|------|------|
| **Viewport** | 3D 씬을 보고 편집하는 메인 작업 공간 |
| **Content Browser** | 프로젝트의 모든 에셋을 관리하는 곳 |
| **World Outliner** | 레벨에 배치된 액터들의 계층 구조 |
| **Details** | 선택한 오브젝트의 속성을 편집 |
| **Toolbar** | 자주 사용하는 기능에 빠르게 접근 |

---

## 🎯 실습 내용

* Epic Games Launcher 설치
* Unreal Engine 5 다운로드 및 설치
* 첫 프로젝트 생성 및 에디터 실행
* 에디터 인터페이스 탐색
* 기본 조작법 실습

---

## 💡 다음 단계

* 기본 레벨 디자인
* Blueprint 비주얼 스크립팅
* 액터 배치 및 조작
* 라이팅 및 머티리얼 기초
* 게임 플레이 구현

---

## 🔗 참고 자료

* [Unreal Engine 공식 문서](https://docs.unrealengine.com/)
* [Unreal Engine 유튜브 채널](https://www.youtube.com/UnrealEngine)
* Epic Games Launcher 다운로드 페이지