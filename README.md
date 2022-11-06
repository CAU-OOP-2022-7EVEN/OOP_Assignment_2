## Environment
| Type | Content |
|:---|:---|
| OS | Ubuntu 20.04.1 Desktop |
| Architecture | amd64 |
| Compiler | Cmake 3.23 |

## Project Structure
> Directory Root( ./ )
>> Source Code for Presentation - Includes QT GUI Related Code. So it would not be compiled without QT Development Environment

> Directory OOP_Assignment2_VS
>> Source Code for Assignment Submit. Professer can run codes inside this directory with Visual Studio.

## Execution
- If QT Development Environment is NOT Setted
> Open OOP_Assignment2_VS Directory with Visual Studio.
- If QT Development Environment is Setted
> Just run Root Directory as CMake Project.


## Notice for Development
- 다들 앞으로 깃에서 받을때 원본(CAU~~ 계정) 말고 자기 계정에 Fork 된것만 받도록 해주세요!
- 코드 작업 시 주석 상세히 작성해주세요
- PR 요청 시, `Assignees -> 작업자, Reviewers -> 선장님`으로 설정해주세요
- PR 요청 시, 제목은 `[ADD or UPDATE] PR 내용`으로 적어주세요
- Commit 메세지 작성 시, `작업종류 파일명 : 작업내용`으로 작성해주세요
    - Commit은 최대한 많이 쪼개주세요
- Git Command는 [다음 정리본](https://yymin1022.notion.site/Git-ebcd92cdb69e4f6aab69ebe53c26d7af)을 참고해주세요
- 혹시 다른환경 쓰시는분들 계시면 gitignore 파일 수정해서 쓸모없는 세팅파일이 커밋되지 않게 주의 부탁드리겠슴미다..
    - 커밋에서 제외할 폴더나 파일 목록에 추가해주면 돼요

## Build & Start

``` bash
$ brew install cmake
```

``` bash
$ cmake CMakeLists.txt
$ Make
$ ./OOP_Assignment_2
```
