# flightProject

## Инсткрукция по сборке c++ проекта:

BUILD_DIR - папка для сборки

PROJ_DIR - относительный путь к c++

```console
mkdir -p BUILD_DIR
cd BUILD_DIR
cmake PROJ_DIR
```

## Запуск c++ проекта:

```console
make
```


## Инструкция по запуску python скриптов:

```console
python3 -m venv venv
. ./venv/bin/activate
(venv) pip install -r requirements.txt 

python3 scripts/SCRIPT_FILE.py 
```
