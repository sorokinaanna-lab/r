#FROM python:3
#ADD sh.py /
#CMD ["python", "./sh.py"]



FROM python:3.8

WORKDIR /code
COPY requirements.txt .
RUN pip install -r requirements.txt
COPY . .

# �������, ����������� ��� ������� ����������
CMD [ "python", "./sh.py" ]