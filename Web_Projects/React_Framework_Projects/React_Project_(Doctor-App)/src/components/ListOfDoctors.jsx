import {useEffect, useState} from "react";
import axios from "axios";
import DoctorListTile from "./DoctorListTile.jsx";
import {ClockLoader} from "react-spinners";

const ListOfDoctors = () => {
    const [doctors, setDoctors] = useState()
    const [loading, setLoading] = useState(true)

    const onDelete = (doctorId) => {
        setLoading(true)
        axios.delete(`/api/doctors/${doctorId}`)
            .then((r) => {
                setDoctors((prev) => {
                    return prev.filter((d) => d.id !== doctorId)
                })
            })
            .catch((error) => {})
            .finally(() => {
                setLoading(false)
            })
    }
    const getDoctors = () => {
        setLoading(true)
        axios.get("/api/doctors")
            .then((r) => {
                setDoctors(r.data)
            })
            .catch((error) => {})
            .finally(() => {
                setLoading(false)
            })
    }

    useEffect(() => {
        getDoctors();
    }, []);

    if (loading) {
        return <div className="h-full w-full flex justify-center items-center">
            <ClockLoader color="white" />
        </div>
    }

    return (
        <div className="flex flex-col gap-2">
            {
                doctors?.map((doctor) => <DoctorListTile key={doctor.id} onDelete={onDelete} doctor={doctor} />)
            }
        </div>
    );
};

export default ListOfDoctors;