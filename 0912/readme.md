# ⚙️ Windows 콘솔 한글 인코딩 설정 (09/12)

## 📌 개요

Windows 콘솔 환경에서 C/C++ 프로그램 실행 시 한글이 깨지는 문제를 해결하는 방법을 학습했습니다.

---

## 🔧 한글 인코딩 문제 해결

### 문제 상황

Windows 콘솔에서 한글 출력 시 깨진 문자가 나타나는 현상

### 해결 방법

#### 1. 필수 헤더 파일 포함

```c
#include <windows.h>  // Windows API 사용을 위해 필수
```

#### 2. main 함수 초기화 코드 추가

```c
int main() {
    // UTF-8 인코딩 설정 (프로그램 시작 시 반드시 작성)
    SetConsoleOutputCP(CP_UTF8);  // 출력 코드 페이지 설정
    SetConsoleCP(CP_UTF8);        // 입력 코드 페이지 설정
    
    // 이후 프로그램 코드 작성
    printf("한글이 정상적으로 출력됩니다.\n");
    
    return 0;
}
```

---

## 📝 코드 설명

| 함수 | 기능 |
|------|------|
| `SetConsoleOutputCP(CP_UTF8)` | 콘솔 출력을 UTF-8로 설정 |
| `SetConsoleCP(CP_UTF8)` | 콘솔 입력을 UTF-8로 설정 |

### CP_UTF8 상수

* Windows에서 UTF-8 인코딩을 나타내는 코드 페이지 상수
* 65001 값을 가짐

---

## ✅ 적용 결과

* ❌ 적용 전: `���湲�` (깨진 문자)
* ✅ 적용 후: `한글` (정상 출력)

---

## 💡 주의사항

1. **반드시 main 함수 시작 부분**에 인코딩 설정 코드를 작성해야 합니다.
2. `windows.h` 헤더 파일이 포함되어야 합니다.
3. 다른 콘솔 출력 함수(`printf`, `puts` 등) 사용 전에 설정해야 합니다.

---

## 📁 실습 파일

폴더 내 모든 `.c`, `.cpp` 파일에서 이 방법을 적용하여 한글 출력 문제를 해결했습니다.

---

## 🔗 참고

* [Windows Console API Documentation](https://docs.microsoft.com/en-us/windows/console/)
* Code Page 65001 (UTF-8)
