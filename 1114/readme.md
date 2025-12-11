# Unity 기본 학습 정리 (README)

## 1. 캐릭터 이동을 위한 기본 환경 구성

Unity에서 캐릭터 이동 및 물리 환경을 실습하기 위해 다음과 같은 단계를 진행했습니다.

---

## 2. 바닥(Floor) 만들기

### 2.1 Cube 추가하기

* **Hierarchy → Create → 3D Object → Cube** 선택하여 큐브 생성.

### 2.2 Cube 위치 변경하기

* **Inspector → Transform → Position** 값을 아래처럼 설정:

  * `0, 0, 0`

### 2.3 Cube 이름 변경하기

* Hierarchy에서 Cube 우클릭 → **Rename** → `Floor` 로 변경.

### 2.4 Cube 크기 변경하기

* **Inspector → Transform → Scale** 값을 아래처럼 설정하여 바닥 생성:

  * `10, 0.5, 5`

---

## 3. 벽 만들기

* 같은 방식으로 Cube를 추가 후 Scale, Position을 조정하여 벽을 생성.
* 예시:

  * Scale: `10, 2, 0.5`
  * Position: `0, 1, -2.5`

---

## 4. 물리 동작 설정

Unity의 물리 시스템을 활용하여 오브젝트 간 충돌 및 중력 적용을 실습했습니다.

### 4.1 Rigidbody 추가

* 오브젝트 선택 → **Inspector → Add Component → Rigidbody**
* Rigidbody를 추가하면:

  * 중력(Gravity) 적용
  * 물리 충돌 처리

### 4.2 Collider 확인

* Cube에는 기본적으로 **Box Collider**가 적용됨
* 필요 시 Sphere Collider, Capsule Collider 등 변경 가능

---

## 5. 공(Ball) 만들기

### 5.1 Sphere 추가

* **Hierarchy → Create → 3D Object → Sphere**

### 5.2 Transform 조정

* Position 예시: `0, 5, 0` (높이에서 떨어지도록)

### 5.3 공 속성 적용

* **Rigidbody 추가**해 물리 적용
* Bounciness(탄성) 추가를 위해 **Physic Material** 설정 가능

---

## 6. 전체적으로 배운 내용 요약

* 3D 오브젝트 생성(Cube, Sphere)
* Transform(Position, Rotation, Scale) 조정
* 바닥 및 벽 구성하기
* Rigidbody를 이용한 물리 동작 적용
* Collider의 역할 이해
* 공(Sphere)에 물리 속성 적용하기

---

이 파일은 수업 시간에 실습한 내용을 정리한 README입니다. 필요한 내용을 자유롭게 수정·추가하여 활용할 수 있습니다.
