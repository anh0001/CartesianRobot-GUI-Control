# Pull Request Template

## Description
Deskripsi dari robot kartesian pergerakan X dan Y yang diinput melalui GUI dari Python dapat berbunyi sebagai berikut:

---

**Deskripsi Robot Kartesian dengan GUI Python**

Robot ini merupakan sistem pergerakan kartesian yang dapat dikendalikan melalui antarmuka pengguna grafis (GUI) yang dibangun dengan menggunakan bahasa pemrograman Python. Robot ini memiliki dua sumbu utama, yaitu sumbu X dan sumbu Y, yang memungkinkan pergerakan linier pada bidang datar.

**Fitur Utama:**

1. **Kontrol Melalui GUI:** Pengguna dapat mengontrol pergerakan robot dengan memberikan input koordinat X dan Y melalui GUI Python.

2. **Antarmuka Pengguna Yang Ramah:** GUI disusun agar mudah digunakan, menyediakan area input untuk koordinat X dan Y, serta tombol-tombol kontrol seperti "Move" untuk memulai pergerakan robot.

3. **Real-Time Feedback:** Sistem memberikan umpan balik waktu nyata tentang posisi robot selama pergerakan, memungkinkan pengguna untuk memonitor pergerakan secara langsung.

4. **Koordinat dalam Satuan Fisik:** Robot memahami koordinat yang dimasukkan dalam satuan fisik tertentu, seperti milimeter atau sentimeter, dan mengubahnya menjadi pergerakan motor yang sesuai.

5. **Kecepatan dan Akselerasi Terkontrol:** Kecepatan dan akselerasi robot dapat diatur sesuai kebutuhan, memungkinkan kontrol yang halus dan presisi.

**Cara Kerja:**

1. **Input Koordinat:** Pengguna memasukkan nilai koordinat X dan Y pada GUI Python.

2. **Konversi Koordinat:** Sistem mengonversi koordinat tersebut ke langkah-langkah motor, mempertimbangkan parameter seperti jumlah langkah per revolusi dan radius roda.

3. **Pergerakan Motor:** Robot memulai pergerakan linier ke koordinat yang diinginkan dengan menggerakkan motor pada sumbu X dan Y secara simultan.

4. **Monitoring Real-Time:** GUI menampilkan posisi aktual robot secara real-time selama pergerakan, memungkinkan pengguna memantau pergerakan dengan akurat.

5. **Berhenti dan Kontrol:** Pengguna dapat menghentikan pergerakan robot kapan pun dengan menggunakan tombol "Stop", dan juga dapat mengontrol kecepatan dan akselerasi pergerakan.

Robot kartesian dengan GUI Python ini dapat digunakan dalam berbagai aplikasi, termasuk pemosisian presisi, pemindahan barang, atau tugas-tugas lain yang melibatkan pergerakan dua dimensi. Dengan antarmuka pengguna yang intuitif, pengoperasian robot menjadi lebih mudah dan dapat diakses oleh berbagai kalangan.

Fixes # (issue number)

## Type of change

Please delete options that are not relevant.

- [ ] Bug fix (non-breaking change which fixes an issue)
- [ ] New feature (non-breaking change which adds functionality)
- [ ] Breaking change (fix or feature that would cause existing functionality to not work as expected)
- [ ] This change requires a documentation update

## How Has This Been Tested?

Please describe the tests that you ran to verify your changes. Provide instructions so we can reproduce. Please also list any relevant details for your test configuration.

- [ ] Test A
- [ ] Test B

## Checklist:

Before submitting your pull request, please review the following checklist:

- [ ] I have performed a self-review of my own code or materials.
- [ ] I have made corresponding changes to the documentation.
- [ ] I have checked my code and corrected any misspellings or errors.
- [ ] I have commented my code, particularly in hard-to-understand areas.
- [ ] I have made sure that my changes generate no new warnings.
- [ ] Any dependent changes have been merged and published in downstream modules.

## Additional Information:

Include any additional information or context about the pull request here.
